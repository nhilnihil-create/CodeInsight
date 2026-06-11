#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;

int main()
{
    ll n;
    ll sum=0;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        if(i%3!=0&&i%5!=0)
            sum+=i;
    }
    printf("%lld\n",sum);
    return 0;
}
