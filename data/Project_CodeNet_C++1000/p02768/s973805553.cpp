#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod=1000000007;

ll fpow(ll b,ll e)
{
    ll res=1;
    while(e)
    {
        if(e&1) res=(res*b)%mod;
        b=(b*b)%mod;
        e/=2;
    }
    return res;
}

ll ch(ll n,ll k)
{
    ll res=1;
    for(ll i=n;i>n-k;i--) res=(res*i)%mod;
    for(ll i=1;i<=k;i++) res=(res*fpow(i,mod-2))%mod;
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,a,b;
    cin >> n >> a >> b;
    ll res=((fpow(2,n)-1-ch(n,a)-ch(n,b))%mod+mod)%mod;
    cout << res << "\n";
    return 0;
}
