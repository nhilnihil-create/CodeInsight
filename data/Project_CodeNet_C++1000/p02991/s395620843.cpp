#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g (n);
    int u, v;
    rep (i, 0, m) {
        cin >> u >> v;
        g[--u].push_back (--v);
    }
    int dist[n][3];
    rep (i, 0, n) rep (j, 0, 3) dist[i][j] = inf;
    queue<pint> q;
    int s, t;
    cin >> s >> t;
    q.push ({--s, 0});
    dist[s][0] = 0;
    while (!q.empty()) {
        int now = q.front().first, cnt = q.front().second;
        q.pop();
        // cout << now << " ";
        for (auto nx : g[now]) {
            if (dist[nx][(cnt + 1) % 3] > dist[now][cnt] + 1) {
                dist[nx][(cnt + 1) % 3] = dist[now][cnt] + 1;
                q.push ({nx, (cnt + 1) % 3});
            }
        }
    }
    /*
    rep (i, 0, n) {
        rep (j, 0, 3) cout << dist[i][j] << " ";
        cout << "\n";
    }
    */
    if (dist[--t][0] == inf) {
        cout << "-1\n";
    } else {
        cout << dist[t][0] / 3 << "\n";
    }
}