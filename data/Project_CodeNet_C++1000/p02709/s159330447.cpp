#include <bits/stdc++.h>
using namespace std;
long long dp[2020][2020];
int main() {
    int n; cin >> n;
    int a[n]; for (int &i : a) cin >> i;
    int p[n]; iota(p, p + n, 0);
    sort(p, p + n, [&] (int x, int y) {
        return a[x] > a[y];
    });
    for (int i = 0; i < n; i++) {
        for (int j = 0; i + j < n; j++) {
            int k = i + j;
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + 1LL * a[p[k]] * abs(p[k] - i));
            dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + 1LL * a[p[k]] * abs(p[k] - (n - 1 - j)));
        }
    }
    long long ans = 0;
    for (int i = 0; i <= n; i++) 
        ans = max(ans, dp[i][n - i]);
    cout << ans;
}