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
    ll n;
    cin>>n;
    if(n<2)
    {
        cout<<0<<endl;
        return;
    }
    ll ans=mod_pow(10,n,mod);
    ans-=((mod_pow(9,n,mod)));
    ans%=mod;
    ans-=((mod_pow(9,n,mod)));
    ans%=mod;
    ans+=(mod_pow(8,n,mod));
    ans=(ans+mod)%mod;
    cout<<ans;
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
