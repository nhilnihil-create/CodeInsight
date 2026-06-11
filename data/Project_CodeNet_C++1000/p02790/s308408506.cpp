#include <iostream>

int main()
{
    int a,b;
    std::cin>>a>>b;
    if (a>b)
        for (int i=0; i<a; i++) std::cout<<b;
    else for (int i=0; i<b; i++) std::cout<<a;
    return 0;
}
