#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define rep(i,n) for(int i=0;i<n;++i)
const int MAX = 510000;
const int MOD = 1000000007;

ll modpow(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

ll comb(ll n, ll k) {
    ll x = 1;
    for(int i=n-k+1; i<=n; i++) {
        x = x*i%MOD;
    }

    ll y = 1;
    for(int i=1; i<=k; i++) {
        y = y*i%MOD;
    }
    y = modpow(y, MOD-2);

    return x*y%MOD;
}

int main(){
    int n,k; cin >> n >> k;
    for(int i=1;i<=k;++i){
        cout << (comb(k-1,i-1) * comb(n-k+1,i))%MOD << endl;
    }
}