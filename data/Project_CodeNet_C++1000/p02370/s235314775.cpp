#include<vector>

struct TopologicalSort {
    int n;
    std::vector<std::vector<int>> G;
    std::vector<int> indeg;
    TopologicalSort(int n) : n(n), G(n, std::vector<int>()), indeg(n) {}
    void addEdge(int from, int to) {
        G[from].push_back(to);
        indeg[to]++;
    }
    std::vector<int> getSorted() {
        std::vector<int> stk, ret;
        for (int i = 0; i < n; i++) { if (indeg[i] == 0) { stk.push_back(i); }}
        while (!stk.empty()) {
            int i = stk.back();
            stk.pop_back();
            ret.push_back(i);
            for (int j = 0; j < G[i].size(); j++) {
                if (--indeg[G[i][j]] == 0) { stk.push_back(G[i][j]); }
            }
        }
        return ret;
    }
};

#include<bits/stdc++.h>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;
    TopologicalSort ts(V);
    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        ts.addEdge(s, t);
    }
    vector<int> ans = ts.getSorted();
    for (int i = 0; i < V; i++) { cout << ans[i] << endl; }
}
