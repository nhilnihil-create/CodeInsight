#include <bits/stdc++.h>
#define ll long long
#define arena ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
 
ll mod=1e9+7;

ll power(ll a,ll b)
{
    if(b==0)
    return 1;
    
    ll x=0;
    if(b%2==0)
    {
        x=power(a,b/2)%mod;
        return ((x%mod)*(x%mod))%mod;
    }
    else
    {
        x=power(a,b-1)%mod;
        return ((a%mod)*(x%mod))%mod;
    }
}
 
int main()
{
    arena
    ll n,k;
    cin>>n>>k;
    ll dp[k+1];
    for(ll i=k;i>=1;i--)
    {
        dp[i]=power(k/i,n)%mod;
        for(ll j=2*i;j<=k;j=j+i)
        {
            dp[i]=dp[i]-dp[j];
        }
    }
    
    //cout<<
    
    ll sum=0;
    for(ll i=1;i<=k;i++)
    {
        sum=(sum%mod+(dp[i]%mod*i%mod)%mod)%mod;
    }
    cout<<sum;
}