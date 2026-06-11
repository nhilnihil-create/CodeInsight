#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1 << 29;
const int MOD = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;

    // シグマ計算をするとkからn+1までの和をいい感じに計算できる
    // 答えは
    // M = N + 1, L = K - 1とおくと、
    // M(M^2 + 5) / 6 + L(2L^2 + 3L - 5 - 3M(L+1)) / 6となる

    long long m = n + 1;
    long long l = k - 1;
    long long ans = m * (m * m + 5) / 6 + l * (2 * l * l + 3 * l - 5 - 3 * m * (l + 1)) / 6;
    cout << ans % MOD << endl;
}