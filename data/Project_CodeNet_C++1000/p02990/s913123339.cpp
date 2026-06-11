#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll  long long
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll mod=1e9+7;
ll fact[2009],inv[2009];
ll f(ll b,ll p){
    ll power=b,ret=1;
    while (p>0){
        if (p&1)
            ret=ret*power%mod;
        power=power*power%mod;
        p=p>>1;
    }
    return ret%mod;
}
int main()
{
    FASTINOUT;
    ll x,k;
    cin>>x>>k;
    fact[0]=1;
    inv[0]=f(1,mod-2);
    for (int i=1;i<=x;i++){
        fact[i]=i*fact[i-1]%mod;
        inv[i]=f(fact[i],mod-2)%mod;
    }
    for (int i=1;i<=k;i++){
        ll ans=0;
        if (i<=x-k+1){
            ll kl=fact[k-1]*inv[i-1]%mod*inv[k-i]%mod;
            ll op=fact[x-k+1]*inv[i]%mod*inv[x-k+1-i]%mod;
            ans=kl*op%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}
