#include<iostream>

int main()
{
    int a,b;
    std::cin>>a>>b;
    ((a+b)%2==0)?
    std::cout<<(a+b)/2<<std::endl:
    std::cout<<"IMPOSSIBLE"<<std::endl;
}
