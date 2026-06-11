#include<iostream>
#include<cstdio>
using namespace std;

int gcd(int a,int b)
{
    if(a%b==0)return b;
    else return gcd(b,a%b);
}

main()
{
    long long  a,b;
    scanf("%lld%lld",&a,&b);
    printf("%lld\n",a/gcd(a,b)*b);
    return 0;
}