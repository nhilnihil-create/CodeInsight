#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
long long gcd(long long x, long long y)
{
    return y == 0 ? x : gcd(y, x % y);
}
int main()
{
    //ios::sync_with_stdio(false);
    long long a,b;
    scanf("%lld %lld",&a,&b);
    long long t = gcd(a, b);
    long long cnt = 1;
    long long lim = t;
    for(long long i = 2;i * i <= t;i++)
    {
        if(t % i == 0)
        {
            cnt++;
            while(t % i == 0)
            {
                t = t / i;

            }
        }
    }
    if(t > 1)
        cnt++;
    printf("%d\n",cnt);
    return 0;
}
