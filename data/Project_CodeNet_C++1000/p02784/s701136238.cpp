#include <iostream>

int h,n;
int a[10000];

int main()
{
    std::cin>>h>>n;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int tmp;
        std::cin>>tmp;
        sum+=tmp;
    }
    if(sum>=h)std::cout<<"Yes"<<std::endl;
    else std::cout<<"No"<<std::endl;
}