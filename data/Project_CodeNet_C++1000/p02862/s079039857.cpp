#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll MOD = 1e9 + 7;
const int MAX = 1510000;
int X, Y;

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

int combi(int n, int m) {
    if (n < m) return 0;
    if (n < 0 || m < 0) return 0;
    return fac[n] * (finv[m] * finv[n - m] % MOD) % MOD;
}

void solve() {
    COMinit();
    cin >> X >> Y;
    int r = (X + Y) % 3;
    if (r != 0) {
        cout << 0 << endl;
    } else {
        int n = (X + Y) / 3;
        P min_p = P(2 * n, n);
        int m = min_p.first - X;
        cout << combi(n, m) << endl;
    }
}

int main() {
    solve();
    return 0;
}
