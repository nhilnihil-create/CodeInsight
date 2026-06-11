#include<bits/stdc++.h>
using namespace std;

long long dp[3002][3002],mod=998244353,ara[3003],n;

long long solve(long long idx,long long cap)
{
    if(idx==n+1)
    {
        if(cap==0)return 1;
        else{ return 0; }
    }
    else if(dp[idx][cap]!=-1)return dp[idx][cap];
    else
    {
        long long p=0,q=0;

        if((cap-ara[idx])>=0)p=solve(idx+1,cap-ara[idx]);
        q=solve(idx+1,cap);  q=(q*2)%mod;

        dp[idx][cap]=(p+q)%mod;   return dp[idx][cap];


    }


}

int main()
{

    long long s,a,b,c,ans,i;
    scanf("%lld %lld",&n,&s);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&ara[i]);
    }

    memset(dp,-1,sizeof dp);

    ans=solve(1,s);

    printf("%lld\n",ans);


    return 0;
}
