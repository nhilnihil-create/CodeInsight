#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e5 + 5;
int used[maxn][4], inf = 1e9;
vector < int > g[maxn];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, u, v, s, t;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= 3; ++j) used[i][j] = inf;
    cin >> s >> t;
    used[s][1] = 0;
    vector < pair < int, int > > Q = {{s, 1}};
    int head = 0;
    while (head < (int)Q.size()) {
        v = Q[head].first;
        int pos = Q[head++].second, d = used[v][pos];
        if (pos == 3) pos = 1;
        else pos++;
        for (auto u : g[v]) {
            if (used[u][pos] == inf) {
                used[u][pos] = d + 1;
                Q.push_back({u, pos});
            }
        }
    }
    if (used[t][1] == inf) cout << -1;
    else cout << used[t][1] / 3;
    return 0;
}

