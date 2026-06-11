#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll dp [1<<17];
ll binpow(ll a,ll b)
{
    a%=mod;
    ll res = 1;
    while(b>0)
    {
        if(b&1) res = res * a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return res;
}
int main()
{
    ll n,k;
    cin>>n>>k;
    ll ans=0;
    for(int i=k;i>=1;i--)
    {
        dp[i] = binpow(k/i,n);
        for(int j = i+i ; j<=k;j+=i)
            dp[i]-=dp[j];
        ans+=i*dp[i]%mod;
    }
    cout<<ans%mod<<endl;
}
