#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
ll mod=998244353;
ll power(ll a,ll b)
{
    ll result=1;
    while(b>0)
    {
        if(b%2)
        result=(result*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return result;
}
int main()
{
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++)
    cin>>a[i];
    ll p=power(2,mod-2);
    vector<vector<ll> > dp(n+1,vector<ll> (k+3));
    dp[0][0]=power(2,n);
    // cout<<dp[0][0]<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j-a[i]>=0)
            {
                (dp[i][j]+=((dp[i-1][j-a[i]])*p)%mod)%=mod;
            }
            
        }
    }
    cout<<dp[n][k]<<endl;


    
}