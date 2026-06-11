#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
template<class T> ostream& operator<<(ostream& os, const vector<T>& vec) { for (auto &vi: vec) os << vi << " "; return os; }

using Graph = vector<vector<int>>;
vector<vector<int>> tsort(Graph &g) {
    int n = g.size(), k = 0;
    vector<int> indeg(n), que, nxt;
    for (int u = 0; u < n; u++) for (int v: g[u]) ++indeg[v];
    vector<vector<int>> dist(n);
    for (int v = 0; v < n; v++) if (indeg[v] == 0) que.emplace_back(v);
    while (!que.empty()) {
        for (int u: que) {
            dist[k].emplace_back(u);
            for (int v: g[u]) if (--indeg[v] == 0) nxt.emplace_back(v);
        }
        swap(que, nxt); nxt.clear(); k++;
    }
    if (*max_element(indeg.begin(), indeg.end()) != 0) return {};
    return dist.resize(k), dist;
}

int main() {
    int V, E; cin >> V >> E;
    Graph g(V);
    while (E--) {
        int s, t; cin >> s >> t;
        g[s].emplace_back(t);
    }
    for (auto &vec: tsort(g)) for (int v: vec) cout << v << endl;
    return 0;
}
