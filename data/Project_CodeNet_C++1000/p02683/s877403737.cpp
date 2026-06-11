#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;

int main() {
    int n, m, x, ans = INF;
    cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }

    for (int b = 0; b < 1 << n; b++) {
        int cost = 0;
        vector<int> d(m);
        for (int i = 0; i < n; i++) {
            if (b >> i & 1) {
                cost += c[i];
                for (int j = 0; j < m; j++) d[j] += a[i][j];
            }
        }
        bool ok = true;
        for (int j = 0; j < m; j++) {
            if (d[j] < x) ok = false;
        }
        if (ok) ans = min(ans, cost);
    }
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}