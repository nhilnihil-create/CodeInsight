#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;
template<typename T>
struct edge {
  int src, to;
  T cost;
  edge(int to, T cost) : src(-1), to(to), cost(cost) {}
  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}
  edge &operator=(const int &x) {
    to = x;
    return *this;
  }
  operator int() const { return to; }
};
template<typename T>
using Edges = vector<edge<T>>;
template<typename T>
using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<vector<int>>;
template<typename T>
using Matrix = vector<vector<T>>;

/////////////////////////////////////////////////////////////////////
const ll inf = 1LL<<60;

vector<int> tsort(vector<vector<int>> g) {
  int n = g.size();
  vector<int> ret;

  vector<int> in(n, 0);
  for (int i=0; i<n; i++) {
    for (auto v : g[i]) in[v]++;
  }

  queue<int> que;
  for (int i=0; i<n; i++) {
    if (in[i] == 0) que.push(i);
  }

  while (!que.empty()) {
    int v = que.front(); que.pop();
    for (auto u : g[v]) {
      in[u] -= 1;
      if (in[u] == 0) que.push(u);
    }
    ret.push_back(v);
  }

  return ret;
}

int main()
{
  int n,e; cin>>n>>e;
  vector<vector<int>> g(n);
  rep(i, e) {
    int u,v; cin>>u>>v;
    g[u].push_back(v);
  }
  vector<int> sv = tsort(g);
  for (auto v : sv) cout << v << endl;

  return 0;
}

