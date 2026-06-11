#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

const int inf = 1 << 30;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;
    vt<string> v(n);
    for (auto &i : v) cin >> i;

    vt<vt<int>> dist(n, vt<int>(m, inf));
    dist[0][0] = v[0][0] == '#';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i) dist[i][j] = min(dist[i][j], dist[i - 1][j] + 
                    (v[i][j] == '#' && v[i - 1][j] == '.'));
            if (j) dist[i][j] = min(dist[i][j], dist[i][j - 1] +
                    (v[i][j] == '#' && v[i][j - 1] == '.'));
        }
    }

    cout << dist.back().back();
}
