#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    long long n,num=0,i;
    scanf("%lld",&n);
    for(i=1; i<=n; i++)
    {
        if(i%3==0)
            continue;
        else if(i%5==0)
            continue;
        else if(i%3==0&&i%5==0)
            continue;
        else
            num+=i;
    }
    printf("%lld\n",num) ;
    return 0;
}