#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")

#include <bits/stdc++.h>

#include <ext/numeric>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define all(v) begin(v), end(v)

typedef long long Long;
typedef vector<int> vi;

const int N = 1e5 + 5;

struct DSU {
  int parent[N];
  void init() {
    for (int i = 0; i < N; ++i) {
      parent[i] = i;
    }
  }
  int getRoot(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getRoot(parent[x]);
  }
  void join(int x, int y) {
    x = getRoot(x);
    y = getRoot(y);
    parent[x] = y;
  }
} dsu;

struct Edge {
  int from, to;
  bool out_to = false;
};

vector<Edge> edges;
vector<int> mst_adj[N];
bool deg[N];

void kruskal() {
  dsu.init();
  for (int i = 0; i < edges.size(); ++i) {
    auto& edge = edges[i];
    if (dsu.getRoot(edge.from) == dsu.getRoot(edge.to)) {
      edge.out_to = false;
      deg[edge.from] ^= 1;
    } else {
      dsu.join(edge.from, edge.to);
      mst_adj[edge.from].emplace_back(i);
      mst_adj[edge.to].emplace_back(i);
    }
  }
}

void dfs(int node, int parent, int p_edge) {
  for (int v : mst_adj[node]) {
    auto& edge = edges[v];
    int to = edge.from ^ edge.to ^ node;
    if (to == parent) continue;
    dfs(to, node, v);
  }
  if (deg[node]) {
    if (p_edge == -1) {
      cout << -1 << endl;
      exit(0);
    }
    auto& edge = edges[p_edge];
    if (node == edge.to) {
      edge.out_to = true;
    }
    deg[node] ^= 1;
  } else {
    if (p_edge == -1) return;
    auto& edge = edges[p_edge];
    if (node != edge.to) {
      edge.out_to = true;
    }
    deg[parent] ^= 1;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;
  if (n <= 2 || popCnt(n) == 1) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  for (int i = 1; i <= 2; ++i) {
    cout << i << " " << i + 1 << endl;
    cout << i + n << " " << i + 1 + n << endl;
  }
  cout << 3 << " " << n + 1 << endl;
  for (int i = 4; i < n; i += 2) {
    int j = i + 1;
    if (n % 2 == 0 && i == (n & -n)) {
      swap(i, j);
    }
    cout << i << " " << j << endl;
    cout << j << " " << 1 << endl;
    cout << 1 << " " << i + n << endl;
    cout << i + n << " " << j + n << endl;
    if (n % 2 == 0 && j == (n & -n)) {
      swap(i, j);
    }
  }
  if (n % 2 == 0) {
    cout << n << " " << n - (n & -n) + 1 << endl;
    cout << 2 * n << " " << (n & -n) << endl;
  }
  return 0;
}
