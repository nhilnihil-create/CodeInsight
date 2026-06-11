#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <cmath>
#include <map>
#include <set>
#include <queue>

int main(void)
{
    // freopen("aaa.in","r",stdin);
    long long n;
    scanf("%lld",&n);
    long long sum = 0;
    long long tmp = 0;
    for (long long i=1;i<=n;i++)
    {
        tmp+=i;
        sum+=tmp;
    }
    for (int i=1;i<n;i++)
    {
        long long x,y;
        scanf("%lld%lld",&x,&y);
        if (x>y) x^=y^=x^=y;
        long long tx = x;
        long long ty = n-y+1;
        sum-=tx*ty;
    }
    printf("%lld\n",sum);
    return 0;
}