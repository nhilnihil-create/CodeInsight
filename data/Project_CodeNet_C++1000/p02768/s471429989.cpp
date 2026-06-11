#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <cmath>
#include <map>
#include <tuple>
#include <queue>
#include <stack>
#include <iomanip>

#define MOD (1000000007)
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

const int MAX = 510000;
ll fac[MAX], finv[MAX], inv[MAX];

ll modinv(ll a, ll mod) {
    ll b = mod, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= mod;
    if (u < 0) u += mod;
    return u;
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
ll COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

// 負の数にも対応した % 演算
ll mod(ll val, ll m) {
  ll res = val % m;
  if (res < 0) res += m;
  return res;
}
int main() {

    COMinit();
    
    ll n, a, b;
    cin >> n >> a >> b;

    ll minv = min(a, n-a);
    ll maxv = max(a, n-a);

    ll com_n_a = 1;
    for(ll copy = n; copy > maxv; copy--) {
        com_n_a *= copy % MOD;
        com_n_a %= MOD;
    }
    for(ll copy = 1; copy <= minv; copy++) {
        com_n_a *= inv[copy] % MOD;
        com_n_a %= MOD;
    }

    
    minv = min(b, n-b);
    maxv = max(b, n-b);

    ll com_n_b = 1;
    for(ll copy = n; copy > maxv; copy--) {
        com_n_b *= copy % MOD;
        com_n_b %= MOD;
    }
    for(ll copy = 1; copy <= minv; copy++) {
        com_n_b *= inv[copy] % MOD;
        com_n_b %= MOD;
    }

    //cout << modpow(2, n, MOD) <<","<<com_n_a<<","<<com_n_b  << endl;
    cout << mod(modpow(2, n, MOD) - com_n_a - com_n_b - 1, MOD) << endl;




    return 0;
}
