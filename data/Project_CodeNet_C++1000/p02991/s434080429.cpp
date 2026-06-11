#include <bits/stdc++.h>
using ll = long long;
using namespace std;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v);
    }
    int s, t; cin >> s >> t; s--, t--;

    queue<pair<int, int>> q;
    vector<vector<int>> d(n, vector<int>(3, -1));
    q.emplace(s, 0); d[s][0] = 0;
    while (!q.empty()) {
        int now, cond;
        tie(now, cond) = q.front(); q.pop();
        if (now == t && cond == 0) {
            cout << d[t][0] / 3 << endl;
            return 0;
        }

        for (auto &nxt: g[now]) {
            int ncond = (cond + 1) % 3;
            if (d[nxt][ncond] == -1) {
                d[nxt][ncond] = d[now][cond] + 1;
                q.emplace(nxt, ncond);
            }
        }
    }
    cout << -1 << endl;
    return 0;
}