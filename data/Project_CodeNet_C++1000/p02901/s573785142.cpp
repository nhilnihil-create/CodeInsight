#include<bits/stdc++.h>
using namespace std;
int a[1010], b[1010], c[1010];
int dp[5010];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i] >> b[i];
        for (int j = 1; j <= b[i]; ++j) {
            int x;
            cin >> x;
            c[i] |= (1 << (x - 1));
        }
        
    }
    fill(dp, dp + 5000, 2e9);
    dp[0] = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = (1 << n) - 1; j >= 0; --j) {
        //    cout << j << " " << dp[(j | c[i])] << '\n';
            dp[(j | c[i])] = min(dp[(j | c[i])], dp[j] + a[i]);
           // cout << j << " " << dp[(j | c[i])] << '\n';
        }
    }
    if (dp[(1 << n) - 1] == 2e9) {
        cout << -1;
    } else {
        cout << dp[(1 << n) - 1];
    }
}