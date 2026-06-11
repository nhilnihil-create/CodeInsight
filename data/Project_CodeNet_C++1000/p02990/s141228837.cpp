#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

// 二分累乗法による　a^b mod p
ll mod_pow(ll a,ll b,ll p){
    ll res = 1;
    while(b > 0){
        if(b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

vector<ll> fact;
// n! mod p
void mod_fact(ll n,ll p){
    fact.resize(n+1);
    fact[0] = 1;
    for(int i = 1; i <= n; i++) fact[i] = fact[i-1] * i % p;
}

// nCk mod p
ll mod_comb(ll n, ll k ,ll p){
    if(k > n) return 0;
    return fact[n] * mod_pow(fact[k]*fact[n-k]%p,p-2,p) % p;
}

int main(){
    ll n,k;
    cin >> n >> k;
    mod_fact(n,MOD);
    for(int i = 1; i <= k ; i++){
        ll ans = mod_comb(n-k+1,i,MOD) * mod_comb(k-1,i-1,MOD) % MOD;
        cout << ans << endl;
    }
    return 0;
}
