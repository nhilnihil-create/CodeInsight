#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MAX = 5100000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    ll ans;
    int x, y;
    cin >> x >> y;
    if ((x + y) % 3 != 0) {
        ans = 0;
    } else {
        int m = (2 * x - y) / 3;
        int n = x - 2 * m;
        if (m < 0 || n < 0) {
            ans = 0;
        } else {
            // 前処理
            COMinit();
            // 計算例
            ans = COM(m + n, m);
        }
    }
    cout << ans << endl;
}
