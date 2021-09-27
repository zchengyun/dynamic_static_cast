#include <iostream>
class A
{
public:
    virtual void fun() { std::cout << "fun()" << std::endl; }
};

class B : public A
{
public:
    virtual void f() { std::cout << "f()" << std::endl; }

};
class D :public B
{
public:
    void m() { std::cout << "m()" << std::endl; }
};
int main()
{
    //向下转换：指的是基类向子类的转换。
    D* p = dynamic_cast<D*>(new B()); // 能够判断转型是否安全，如果安全，则返回B对象的地址，否则返回NULL。本例返回NULL。
    if (p)
    {
        p->m();
    }
    else
    {
        std::cout << "Error\n";//执行
    }

    //向上转换：指的是子类向基类的转换。
    A* p1 = dynamic_cast<A*>(new B()); // 能够判断转型是否安全，如果安全，则返回B对象的地址，否则返回NULL。本例返回NULL。
    if (p1)
    {
        p1->fun();//执行
    }
    else
    {
        std::cout << "Error\n";
    }

    //不安全，如果调用子类独有方法会出错
    D* p2 = static_cast<D*>(new B()); 
    if (p2)
    {
        p2->m();//执行
    }
    else
    {
        std::cout << "Error\n";
    }

    delete p;
    delete p1;
    delete p2;
    return 0;


}
