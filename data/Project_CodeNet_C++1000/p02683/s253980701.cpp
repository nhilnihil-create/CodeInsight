#include <bits/stdc++.h>

//#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, x;
    cin >> n >> m >> x;
    int cost[n];
    int a[n][m];
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }
    int res = 1e9;
    for (int i = 0; i < (1<<n); i++) {
        int cnt[m];
        int sum = 0;
        for (int j = 0; j < m; j++) cnt[j] = 0;
        for (int j = 0; j < n; j++) {
            if (i&(1<<j)) {
                sum += cost[j];
                for (int k = 0; k < m; k++) {
                    cnt[k] += a[j][k];
                }
            }
        }
        bool flag = false;
        for (int j = 0; j < m; j++) if (cnt[j] < x) flag = true;
        if (!flag) res = min(res, sum);
    }
    if (res == 1e9) cout << "-1\n";
    else cout << res << '\n';
}
/*

 */