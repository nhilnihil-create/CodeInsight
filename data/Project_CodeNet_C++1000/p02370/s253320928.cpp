#include <bits/stdc++.h>
using namespace std;

bool topologicalSort(const vector<vector<int>>& adj, vector<int>& ord) {
    int N = adj.size();
    vector<int> deg(N);//??\?¬???°
    for(int i = 0; i < N; ++i)
      for(int nv : adj[i])
        ++deg[nv];
    ord.assign(N, -1);
    int t = 0;
    for(int v = 0; v < N; ++v) 
      if(deg[v] == 0)
        ord[t++] = v;

    for(int h = 0; h < t; ++h) {
        int v = ord[h];
        for(int nv : adj[v]) {
            --deg[nv];
            if(deg[nv] == 0)
              ord[t++] = nv;
        }
    }
    return t == N;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(V);
    for(int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
    }
    vector<int> ord;
    topologicalSort(adj, ord);
    for(int x : ord) cout << x << endl;
}