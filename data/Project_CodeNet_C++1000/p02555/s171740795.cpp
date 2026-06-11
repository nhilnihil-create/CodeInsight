#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[1000000+5];
ll arr[1000000+5];
/*arr[0]=1;
dp[0]=1;*/
int main()
{
    /*ll n,x=1,i;
    cin>>n;
    ll mod=1000000007;
    ll dp[n+2]
    for(i=1;i<=n-1;i++)
    {
        x=x*2;
        x=x%mod;
    }
    x=x+n-1;
    x=x%mod;
    cout<<x;*/
    /*ll n;
    cin>>n;
    ll a[n],i;
    for(i=0;i<n;i++)
    {
        cin>>n;
    }*/
    ll n,i;
    cin>>n;
    ll mod=1000000007;
    ll dp[n+10];
    dp[0]=dp[1]=dp[2]=0;
    dp[3]=dp[4]=dp[5]=1;
    for(i=6;i<=n;i++)
    {
        dp[i]=(dp[i-1]+dp[i-3])%mod;
    }
    cout<<dp[n];
}
