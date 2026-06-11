#include <bits/stdc++.h>

using namespace std;

class Dsu {
 public:
  int n; // number of componet
  vector<int> sz, p;
  
  Dsu(int n) : n(n), sz(n, 1), p(n, -1) { }

  int find(int i) {
    if (p[i] == -1) return i;
    return p[i] = find(p[i]);
  }

  bool merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    n--;
    if (sz[u] < sz[v]) {
      p[u] = v;
      sz[v] += sz[u];
    } else {
      p[v] = u;
      sz[u] += sz[v];
    }
    return true;
  }

  bool same(int u, int v) { return find(u) == find(v); }
};

int main() {
  ios_base::sync_with_stdio(false);

  int n, m, op, u, v;
  cin >> n >> m;

  Dsu dsu(n);

  for (int i = 0; i < m; i++) {
    cin >> op >> u >> v;
    if (op == 0) {
      dsu.merge(u, v);
    } else {
      cout << dsu.same(u, v) << '\n';
    }
  }

  return 0;
}
