// #define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B&lang=jp"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

// #include "../../library/graph/topologicalsort.cpp"
// topologically sort the directed graph
// 0-indexed
struct TopologicalSort {
    int n;
    vector<set<int>> G;
    vector<bool> used;
    vector<int> indeg, p;

    TopologicalSort(int size) : n(size), G(n), used(n), indeg(n), p(0) {}

    void addEdge(int s, int t) { G[s].insert(t); }
    void bfs(int s) {
        queue<int> q;
        q.push(s);
        used[s] = 1;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            p.push_back(v);
            for (int u : G[v]) {
                indeg[u]--;
                if (indeg[u] == 0 && !used[u]) {
                    used[u] = 1;
                    q.push(u);
                }
            }
        }
    }
    // returns topologically sorted nodes
    // if p.size() < n, the graph cannot be sorted
    vector<int> build() {
        fill(used.begin(), used.end(), 0);
        fill(indeg.begin(), indeg.end(), 0);
        for (int i = 0; i < n; ++i) {
            for (int v : G[i])
                indeg[v]++;
        }
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0 && !used[i])
                bfs(i);
        }
        return p;
    }
};

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    int v, e;
    cin >> v >> e;
    TopologicalSort graph(v);
    for (int i = 0; i < e; ++i) {
        int s, t;
        cin >> s >> t;
        graph.addEdge(s, t);
    }
    auto ret = graph.build();
    for (auto &r : ret) {
        cout << r << "\n";
    }
    cout << flush;
    return 0;
}
