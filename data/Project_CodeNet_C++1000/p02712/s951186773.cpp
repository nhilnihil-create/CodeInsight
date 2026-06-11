#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#define inf 0x3f3f3f3f
using namespace std;
//long long a[inf]
int da(int i)
{
    if(i%3==0||i%5==0)
        return 1;
    else
        return 0;
}
int main()
{
    long long  sum=0;
    long long n;
    scanf("%lld",&n);
    int m,p;
    for(int i=1;i<=n;i++)
    {
        m=da(i);
        p=da(i);
        if(m==0&&p==0)
            sum+=i;
    }
    printf("%lld\n",sum);
    return 0;
}
