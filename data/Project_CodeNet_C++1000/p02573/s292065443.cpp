#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ii = pair<int, int>;

struct UnionFind {
  vi p, sz;
  int n;

  UnionFind(int n): n(n) {
    p.resize(n);
    sz.assign(n, 1);
    
    for (int i = 0; i < n; i++)
      p[i] = i;
  }

  int find_set(int u) {
    return p[u] = u == p[u] ? u : find_set(p[u]);
  }

  void union_set(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if (v != u) {
      if (sz[u] > sz[v]) swap(u, v);
      p[u] = v;
      sz[v] += sz[u];
    }
  }
};

int main() {
  cin.sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;

  cin >> n >> m;

  UnionFind dsu(n);

  int u, v;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    dsu.union_set(u - 1, v - 1);
  }

  int ans = 0;
  for (int i = 0; i < n; i++)
    ans = max(ans, dsu.sz[dsu.find_set(i)]);

  cout << ans << endl;

  return 0;
}
