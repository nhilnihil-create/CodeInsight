#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
// a^n mod を計算する
ll modpow(ll a, ll n, ll mod) {
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
 
const int MAX = 3000000;
const int MOD = 1000000007;
 
ll fac[MAX], finv[MAX], inv[MAX];
 
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
 
int main() {
    ll X, Y;
    cin >> X >> Y;
    if ((2 * X - Y) % 3 != 0 || ((2 * Y - X) % 3 != 0)) {
        cout << "0\n";
        return 0;
    }
    ll a = (2 * X - Y) / 3;
    ll b = (2 * Y - X) / 3;
    ll mod = pow(10, 9) + 7;
    ll ans = 1;
    for (ll i = a + 1; i <= a + b; i++) {
        ans = (ans * i) % mod;
    }
    COMinit();
    cout << COM(a + b, a) << "\n";
    return 0;
}