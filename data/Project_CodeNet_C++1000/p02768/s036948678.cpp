#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;

const int MOD = 1e9 + 7;
const int MAX = 2 * 10e5 + 1;

template<typename T>
T modPow(T x, T n, const T &mod){
    T res = 1;
    while(n > 0){
        if(n & 1) (res *= x) %= mod;
        (x *= x) %= mod;
        n >>= 1; // nを1bit左にずらす
    }
    return res;
}

V<ll> finv, inv, Com;
void COMinit(){
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll COM(ll n, ll k){
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    ll res = 1;
    for(int i = n; i >= n - k + 1; i--){
        res = res * i % MOD;
    }
    return res * finv[k] % MOD;
}


int main() {
    ll n, a, b; cin >> n >> a >> b;
    finv.resize(MAX);
    inv.resize(MAX);
    COMinit();

    ll ans = (modPow<ll>(2, n, MOD) - 1 - COM(n, a) - COM(n, b)) % MOD;
    ans = (ans + MOD) % MOD;
    cout << ans << endl;
}
