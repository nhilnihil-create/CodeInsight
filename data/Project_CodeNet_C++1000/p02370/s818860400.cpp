#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> topological_sort(const vector<vector<int>> &G) {
  const int N = G.size();
  vector<int> indeg(N, 0);
  for(auto &&vs : G) {
    for(int v : vs) {
      indeg[v]++;
    }
  }
  queue<int> Q;
  for(int i = 0; i < N; ++i) {
    if(indeg[i] == 0) Q.push(i);
  }
  vector<int> ret;
  while(!Q.empty()) {
    int v = Q.front(); Q.pop();
    ret.push_back(v);
    for(int u : G[v]) {
      indeg[u]--;
      if(indeg[u] == 0) Q.push(u);
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  int V, E; cin >> V >> E;
  vector<vector<int>> G(V);
  for(int i = 0; i < E; ++i) {
    int s, t; cin >> s >> t;
    G[s].push_back(t);
  }
  for(auto &&v : topological_sort(G)) {
    cout << v << endl;
  }
}