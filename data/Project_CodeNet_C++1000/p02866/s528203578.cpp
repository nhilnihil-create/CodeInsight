#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(ll i=0;i< (n);i++)
#define rep1(i,n) for(ll i=1;i<= (n);i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

const static ll MOD = 998244353;

ll modcross(ll a,ll n){
    if(n == 0)return 0;
    if(n % 2 == 1)return a+modcross(a,n-1) % MOD;
    ll t = modcross(a,n/2) % MOD;
    return t*2 % MOD;
}

ll modpow(ll a,ll n){
    if(n == 0)return 1;
    if(n % 2 == 1)return a*modpow(a,n-1) % MOD;
    ll t = modpow(a,n/2) % MOD;
    return t*t % MOD;
}

int main(){
    ll n;cin>>n;
    vector<ll> D(n,0);
    rep(i,n)cin>>D[i];
    map<ll,ll> mp;
    rep(i,n){
        mp[D[i]]++;
    }
    if(D[0] != 0 || mp[0] != 1){
        cout<<'0'<<endl;
        return 0;
    }
    ll ans = 1;
    for(int i = 1;i<n;i++){
        ans *= mp[D[i]-1];
        ans %= MOD;
    }
    cout<<ans%MOD<<endl;
    return 0;
}