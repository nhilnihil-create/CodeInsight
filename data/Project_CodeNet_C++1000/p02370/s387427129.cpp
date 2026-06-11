#include "bits/stdc++.h"
using namespace std;

struct StronglyConnectedComponentDecomposition {
    vector<vector<int>> graph, igraph, sccbucket;
    vector<int> vs, sccid;
    int nscc;
    void dfs(int v) {
        sccid[v] = 0;
        for (int u : graph[v]) {
            if (sccid[u] == -1) dfs(u);
        }
        vs.push_back(v);
    }
    void rdfs(int v, int k) {
        sccid[v] = k;
        for (int u : igraph[v]) {
            if (sccid[u] == -1) rdfs(u, k);
        }
    }
    void sccd() {
        sccid.assign(graph.size(), -1);
        for (int v = 0; v < (int)graph.size(); ++v) {
            if (sccid[v] == -1) dfs(v);
        }
        sccid.assign(graph.size(), -1);
        nscc = 0;
        while (!vs.empty()) {
            int v = vs.back(); vs.pop_back();
            if (sccid[v] == -1) rdfs(v, nscc++);
        }
        sccbucket.resize(nscc);
        for (int v = 0; v < (int)graph.size(); ++v) {
            sccbucket[sccid[v]].push_back(v);
        }
    }
};

int main() {
    int V, E;
    cin >> V >> E;
    StronglyConnectedComponentDecomposition sccd;
    sccd.graph.resize(V);
    sccd.igraph.resize(V);
    for (int i = 0; i < E; ++i) {
        int s, t;
        cin >> s >> t;
        sccd.graph[s].push_back(t);
        sccd.igraph[t].push_back(s);
    }
    sccd.sccd();

    for (auto& b : sccd.sccbucket) {
        for (int v : b) cout << v << endl;
    }
}
