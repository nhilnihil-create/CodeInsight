#include <bits/stdc++.h>
using namespace std;

struct Unionfind {
  // tree number
  vector<int> par;
  // constructor
  Unionfind(int n = 1) : par(n, -1) {}
  // search root
  int root(int x) {
    if (par[x] < 0) return x;
    return par[x] = root(par[x]);
  }
  // is same?
  bool issame(int x, int y) { return root(x) == root(y); }

  // add
  // already added, return 0
  bool uni(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return 0;
    if (par[x] > par[y]) swap(x, y);
    par[x] += par[y];
    par[y] = x;
    return 1;
  }
  int size(int x) { return -par[root(x)]; }
};

int main() {
  int n, q;
  cin >> n >> q;
  Unionfind uf(n);
  while (q--) {
    int t, u, v;
    cin >> t >> u >> v;
    if (t)
      cout << uf.issame(u, v) << endl;
    else
      uf.uni(u, v);
  }

  return 0;
}