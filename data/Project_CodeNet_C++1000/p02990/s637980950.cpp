#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
const int MAX = 2001;
int N, K;

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

ll modpow(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

void solve() {
    COMinit();
    cin >> N >> K;
    int RN = N - K + 1;
    for (int i = 1; i <= K; ++i) {
        if (RN < i) cout << 0 << endl;
        else {
            ll x = COM(RN, i);
            ll y = COM(K-1, i-1);
            cout << x * y % MOD << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}
