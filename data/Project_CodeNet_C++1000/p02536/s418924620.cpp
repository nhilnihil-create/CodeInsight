#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
vector<vector<int>> g;
vector<bool> vis;
int n, m, x, y, res(-1);
inline void DFS(const int& x) {
    vis[x] = true;
    for (const int& y : g[x])
        if (!vis[y])
            DFS(y);
}
int main() {
    DAU
    cin >> n >> m;
    g.resize(n + 1);
    while (m--) {
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    vis.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            ++res, DFS(i);
    cout << res;
    PLEC
}
