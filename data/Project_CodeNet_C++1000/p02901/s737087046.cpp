#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
int n, m, a[1001], b[1001], dp[5000], c, mask, res;
int main() {
    DAU
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i] >> b[i];
        mask = 0;
        for (int j = 1; j <= b[i]; ++j) {
            cin >> c;
            mask |= (1 << (c - 1));
        }
        b[i] = mask;
    }
    fill(dp, dp + 5000, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= m; ++i)
        for (int mask = 0; mask < (1 << n); ++mask)
            dp[mask | b[i]] = min(dp[mask | b[i]], dp[mask] + a[i]);
    res = dp[(1 << n) - 1];
    if (res == 1e9)
        res = -1;
    cout << res;
    PLEC
}
