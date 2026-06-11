#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const ll INF=1LL<<60;
const ll MOD=1e9+7;

ll modpow(ll a, ll n, ll mod){
    long long res=1;
    while(n>0){
        if(n & 1) res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

ll modinv(ll a, ll mod){
    return modpow(a, mod-2, mod);
}

ll comb(ll n, ll k, ll mod){
    ll res=1;
    for(ll i=0; i<k; i++){
        res=res*(n-i)%mod*modinv(i+1, mod)%mod;
    }
    return res;
}

int main(){
    ll n, a, b; cin >> n >> a >> b;
    ll ans=modpow(2LL, n, MOD)-1-comb(n, a, MOD)-comb(n, b, MOD);
    ans%=MOD;
    if(ans < 0) ans=MOD+ans;
    cout << ans << endl;
    return 0;
}