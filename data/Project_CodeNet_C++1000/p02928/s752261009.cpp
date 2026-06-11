#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(ll i=0;i< (n);i++)
#define rep1(i,n) for(ll i=1;i<= (n);i++)
using namespace std;
typedef long long ll;
const static ll MOD = (1e+9)+7;

ll modcross(ll a,ll k){
    if(k == 0)return 0;
    if(k % 2 == 1)return (a + modcross(a,k-1)) % MOD;
    ll t = modcross(a,k/2) % MOD;
    return (t * 2) % MOD; 
}
ll modpow(ll a,ll k){
    if(k == 0)return 1;
    if(k % 2 == 1)return (a * modpow(a,k-1)) % MOD;
    ll t = modpow(a,k/2) % MOD;
    return (t * t) % MOD; 
}

int main(){
    ll n,k;cin>>n>>k;
    vector<ll> A(n,0);rep(i,n)cin>>A[i];
    ll ans = 0;
    for(ll i = 0;i<n-1;i++){
        for(ll j = i+1;j<n;j++){
            if(A[i]>A[j])ans += modcross(k,k+1) * modpow(2,MOD-2) % MOD;
            if(A[i]<A[j])ans += modcross(k,k-1) * modpow(2,MOD-2) % MOD;
            ans %= MOD;
        }
    }
    cout<<ans%MOD<<endl;
    return 0;
}