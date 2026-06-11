#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
#define rep2(i,a,n) for (int i = a; i < n; i++)
using namespace std;
int X, Y;
long long res;

const int MAX = 2 * pow(10, 6) + 10;
const int MOD = pow(10, 9) + 7;
long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;

    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

long long solve() {
    if (2 * X < Y || 2 * Y < X) return 0;
    if ((2 * Y - X) % 3 != 0 || (2 * X - Y) % 3 != 0) return 0;
    int m = (2 * Y - X) / 3;
    int n = (2 * X - Y) / 3;
    return COM(m + n, m);
}
int main() {
    cin >> X >> Y;
    COMinit();
    res = solve();
    printf("%lld\n", res);
    return 0;
}
