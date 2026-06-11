#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define int long long
using pint = pair<int, int>;

int n;
vector<vector<int>> g (100050); // now : {visit}
int dijkstra (int s, int t) {
    int seen[n][3]; // seen[number][amari] : min time
    // q : {visit,count}
    queue<pint> q;
    rep (i, 0, n) rep (j, 0, 3) seen[i][j] = -3;
    seen[s][0] = 0;
    q.push ({s, 0});

    while (!q.empty()) {
        pint p = q.front();
        q.pop();
        int count = p.second;
        int v = p.first;
        for (auto nv : g[v]) {
            int ncount = (count + 1) % 3;
            if (seen[nv][ncount] == -3) {
                seen[nv][ncount] = seen[v][count] + 1;
                q.push ({nv, ncount});
            }
        }
    }
    return seen[t][0] / 3;
}

signed main() {
    int m;
    cin >> n >> m;
    rep (i, 0, m) {
        int u, v;
        cin >> u >> v;
        g[--u].push_back (--v);
    }
    int s, t;
    cin >> s >> t;
    cout << dijkstra (--s, --t) << "\n";
}