#include <iostream>

int main()
{
    unsigned long long int h;
    std::cin>>h;
    unsigned long long s=0,k=1;
    while (h)
    {
        s+=k;
        k*=2;
        h/=2;
    }
    std::cout<<s;
    return 0;
}