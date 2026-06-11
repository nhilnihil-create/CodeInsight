#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N = 2e3 + 5, mod = 1e9 + 7;
int dp[N][N][2];

int solve(int red, int blue, int last) {
    if (red + blue == 0) return 1;
    int &ret = dp[red][blue][last];
    if (ret != -1) return ret;
    ret = 0;
    if (red)
        ret = solve(red - 1, blue, 0);
    if (blue && !last) ret = (ret + solve(red, blue - 1, 1)) % mod;
    return ret;
}

int ncr[N][N];

int starsAndBars(int n, int k) {
    return ncr[n - 1][k - 1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (!j || i == j)ncr[i][j] = 1;
            else ncr[i][j] = (ncr[i - 1][j] + ncr[i - 1][j - 1]) % mod;
        }
    }
    int n, k;
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= k; i++) cout << (solve(n - k, i, 0) * 1LL * starsAndBars(k, i) % mod) % mod << '\n';
    return 0;
}