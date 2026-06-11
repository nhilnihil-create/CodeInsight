#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

struct UnionFind {
  // 子は親のID,親は-サイズ
  vector<int> d;
  UnionFind(int n) : d(n, -1) {}
  int root(int x) {
    if (d[x] < 0) return x;
    return d[x] = root(d[x]);
  }
  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x, y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return root(x) == root(y); }
  int size(int x) { return -d[root(x)]; }
};

int main() {
  ll n, ans = INF;
  cin >> n;
  if (n == 1) {
    puts("1");
    return 0;
  }
  vector<ll> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      int p = x[i] - x[j];
      int q = y[i] - y[j];
      ll cnt = 0;
      UnionFind uf(n);
      for (int k = 0; k < n; ++k) {
        for (int l = 0; l < n; ++l) {
          if (k == l) continue;
          if (x[l] == x[k] + p && y[l] == y[k] + q) uf.unite(k, l);
        }
      }
      unordered_set<ll> st;
      rep(k, n) st.insert(uf.root(k));
      ans = min(ans, (ll)st.size());
    }
  }

  cout << ans << endl;
  return 0;
}
