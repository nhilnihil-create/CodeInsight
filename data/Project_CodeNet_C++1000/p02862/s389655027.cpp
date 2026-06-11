#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;

const int MAX = 1e6;  // 注意

ll fac[MAX], finv[MAX], inv[MAX];

// a^n mod を計算する
ll modpow(ll a, ll n, ll mod = MOD) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

// a^{-1} mod を計算する
ll modinv(ll a, ll mod) {
    return modpow(a, mod - 2, mod);
}

// (a%MOD) * modinv(b, MOD) % MOD で　a/b;
ll moddiv(ll a, ll b, ll mod = 1e9+7){
    ll res = (a%mod) * modinv(b, mod) % mod;
    return (res+mod)%mod ;
}

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


int main(){
    COMinit();
    ll X, Y; cin >> X >> Y;
    if((X+Y)%3 != 0) { cout << 0 << endl; return 0; }
    ll N = (X+Y)/3;
    ll D = abs(X-Y);
    ll K = (min(X, Y) - D) / 3;
    cout << COM(N, K) << endl;


}
