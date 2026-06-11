#include <bits/stdc++.h>
using namespace std;

vector<int> topological_sort(const vector<vector<int>>& g) {
    int n = g.size();
    vector<int> tpl, indeg(n, 0);
    vector<bool> seen(n, false);
    for (int i = 0; i < n; i++) {
        for (auto v : g[i]) indeg[v]++;
    }
    for (int s = 0; s < n; s++) {
        if (indeg[s] == 0 && !seen[s]) {
            queue<int> que; que.emplace(s); seen[s] = true;
            while (!que.empty()) {
                int u = que.front(); que.pop(); tpl.emplace_back(u);
                for (int i = 0; i < g[u].size(); i++) {
                    int v = g[u][i]; indeg[v]--;
                    if (indeg[v] == 0 && !seen[v]) {
                        seen[v] = true; que.emplace(v);
                    }
                }
            }
        }
    }
    if (tpl.size() != n) tpl.clear();
    return tpl;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int s, t;
        scanf("%d%d", &s, &t);
        g[s].emplace_back(t);
    }
    
    vector<int> ans = topological_sort(g);
    for (auto v : ans) printf("%d\n", v);
    return 0;
}
