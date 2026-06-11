#include <bits/stdc++.h>
using namespace std;

class SCC {
    void dfs(int v) {
        if (used[v]) return;
        used[v] = 1;
        for (auto &u : g[v]) dfs(u);
        ord.push_back(v);
    }

    void rdfs(int v) {
        if (~cmp[v]) return;
        cmp[v] = sz;
        for (auto &u : rg[v]) rdfs(u);
    }

public:
    int sz;
    vector<vector<int>> g, rg, dag, group;
    vector<int> cmp, ord, used;

    SCC (int n) : g(n), rg(n), cmp(n, -1), used(n, 0) {}
    SCC (vector<vector<int>> &g) : g(g), rg(g.size()), cmp(g.size(), -1), used(g.size(), 0) {
        for (int v = 0; v < (int)g.size(); ++v) for (int u : g[v]) rg[u].push_back(v);
        build();
    }

    void add_edge(int s, int t) {
        g[s].push_back(t);
        rg[t].push_back(s);
    }

    void build() {
        for (int i = 0; i < (int)g.size(); ++i) dfs(i);
        reverse(ord.begin(), ord.end());
        sz = 0;
        for (int i : ord) if (!~cmp[i]) rdfs(i), ++sz;
        dag.resize(sz); group.resize(sz);
        for (int i = 0; i < (int)g.size(); ++i) {
            for (int j : g[i]) {
                int x = cmp[i], y = cmp[j];
                if (x != y) dag[x].emplace_back(y);
            }
            group[cmp[i]].push_back(i);
        }
    }

    // number of connected components
    int size() { return sz; }

    // the number of the component to which element x belongs
    int operator[](int x) { return cmp[x]; }

    bool same(int x, int y) { return cmp[x] == cmp[y]; }
};

int main() {
    int V, E;
    cin >> V >> E;
    SCC scc(V);
    for (int i = 0; i < E; ++i) {
        int s, t;
        cin >> s >> t;
        scc.add_edge(s, t);
    }
    scc.build();
    for (int i = 0; i < scc.ord.size(); ++i) {
        cout << scc.ord[i] << endl;
    }
}
