#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;


ll modpow(ll N, ll P){
    if(P==0) return 1;
    if(P%2==0){
        ll t =modpow(N, P/2);
        return t*t % mod;
    }
    return N * modpow(N, P-1)%mod;
}

ll n;
ll com(ll k){
    ll u=1;
    for (int i = 0; i < k; ++i) {
        u*=n-i;
        u%=mod;
        if(u<0){
            u+=mod;
        }
    }
    ll d=1;
    for (int i = 0; i < k; ++i) {
        d*=(i+1);
        d%=mod;
        if(d<0){
            d+=mod;
        }
    }
    ll inv=modpow(d,mod-2);
    u=u*inv%mod;
    return u;
}

int main(){
    ll a,b;cin >>n>>a>>b;
    ll ans=modpow(2,n);
    ans-=com(a);
    ans-=com(b);
    ans--;
    ans%=mod;
    if(ans<0){
        ans+=mod;
    }
    cout <<ans <<endl;
    return 0;
}

