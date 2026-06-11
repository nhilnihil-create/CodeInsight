#include <iostream>

int main()
{
    unsigned long long h;
    int n;
    std::cin>>h>>n;
    unsigned long long s=0;
    for(int i=0; i<n; i++)
    {
        int x;
        std::cin>>x;
        s+=x;
    }
    if (s>=h) std::cout<<"Yes";
    else std::cout<<"No";
    return 0;
}