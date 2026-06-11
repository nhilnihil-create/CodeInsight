#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1<<30;
const ll LINF = 1LL<<60;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m, X; cin >> n >> m >> X;
    vector<int> c(n);
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }

    int ans = LINF;

    for (unsigned int x = 0; x < (1<<n); x++) {
        int cost = 0;
        vector<int> l(m, 0);
        for (int i = 0; i < n; i++) {
            if (x & (1<<i)) {
                cost += c[i];
                for (int j = 0; j < m; j++) l[j] += a[i][j];
            }
        }
        bool ok = true;
        for (auto j : l) if (j < X) ok = false;
        if (ok) ans = min(ans, cost);
    }

    if (ans == LINF) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}