#include <bits/stdc++.h>
using namespace std;

struct TopologicalSort {
   vector<int> used, indeg, res;
   vector<set<int>> G;

   TopologicalSort() {}
   TopologicalSort(int n):G(n), used(n, 0), indeg(n, 0) {}

   void add_edge(int s, int t) {
      G[s].emplace(t);
      indeg[t]++;
   }

   void bfs(int s) {
      queue<int> que;
      que.emplace(s);
      used[s] = 1;
      while(!que.empty()) {
         int v = que.front(); que.pop();
         res.emplace_back(v);
         for(int u:G[v]) {
            indeg[u]--;
            if(indeg[u] == 0 && !used[u]) {
               used[u] = 1;
               que.emplace(u);
            }
         }
      }
   }

   vector<int> build() {
      int n = G.size();
      for(int i=0; i<n; ++i) if(indeg[i] == 0 && !used[i]) bfs(i);

      return res;
   }
};

int main() {
   int V, E; cin >> V >> E;
   TopologicalSort tp(V);
   for(int i=0; i<E; ++i) {
      int u, v; cin >> u >> v;
      tp.add_edge(u, v);
   }
   auto res = tp.build();
   for(int i=0; i<V; ++i) cout << res[i] << endl;
}
