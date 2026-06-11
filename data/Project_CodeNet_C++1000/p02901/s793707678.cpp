#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<vector>
using namespace std;
#define ll long long
#define db double
ll dp[1<<12+5];
ll a[1005];
ll key[1005];
ll pow2[15];

int main()
{
    ll n,m;

    pow2[0]=1;
    for(ll i=1;i<15;i++)pow2[i]=pow2[i-1]<<1;
    memset(dp,1e9+5,sizeof(dp));

    scanf("%lld %lld",&n,&m);

    dp[0]=0;

    for(ll i=1;i<=m;i++)
    {
        ll b,t=1;
        scanf("%lld %lld",&a[i],&b);
        for(ll j=1;j<=b;j++)
        {
            ll tmp;
            scanf("%lld",&tmp);
            key[i]=key[i]+pow2[tmp-1];
        }
    }

    for(ll j=0;j<pow2[n];j++)
    {
        for(ll i=1;i<=m;i++)
        {
            dp[j|key[i]]=min(dp[j]+a[i],dp[j|key[i]]);
        }
    }


    if(dp[pow2[n]-1]>=1e9+5)
    {
        printf("-1");
        return 0;
    }
    printf("%lld",dp[pow2[n]-1]);
    return 0;
}


