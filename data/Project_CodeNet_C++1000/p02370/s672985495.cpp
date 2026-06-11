#include<bits/stdc++.h>
using namespace std;

int V, E;
vector<unordered_set<int>> redge;
// bool redge[10000][10000];

// bool memo[10000];
unordered_set<int> memo;
void topological_sort(int u) {
//   if(memo[u]) return;
//   memo[u] = true;
//   for(int v = 0; v < V; ++v) if(redge[u][v]) topological_sort(v);
  if(memo.count(u)) return;
  memo.insert(u);
  for(int v: redge[u]) topological_sort(v);
  cout << u << endl;
}

int main() {
  cin >> V >> E;
  redge.resize(V);
  for(int i = 0; i < E; ++i) {
    int u, v;
    cin >> u >> v;
    redge[v].insert(u);
//     redge[v][u] = true;
  }
  for(int i = 0; i < V; ++i) topological_sort(i);
}