#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi 3.141592653589793238
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mod 1000000007

ll mod_pow(ll a,ll b,ll m)
{
    ll res = 1;
    while(b)
    {
        if(b&1)
        {
            res=(res*a) % m;
        }
        a=(a*a) % m;
        b>>=1;
    }
    return res;
}

void solve()
{
    ll s;
    cin>>s;
    vector<ll> dp(s+1,0);
    dp[0]=1;
    for(ll i=3;i<=s;i++)
    {
        for(ll j=i-3;j>=0;j--)
            dp[i]=(dp[i]+dp[j])%mod;
 
    }
    cout<<dp[s]%mod;
    return;
}

int main()
{
    FAST;
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
      #endif
    ll q;
    q=1;
    // sieve();
    // cin>>q;
    while(q--)
        solve();
    return 0;
}
