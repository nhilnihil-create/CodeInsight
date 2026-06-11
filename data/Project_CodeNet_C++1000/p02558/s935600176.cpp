#include<bits/stdc++.h>
using namespace std;
struct UF {
  vector<int> par, siz;
  UF(int n): par(n), siz(n,1) {
    for (int i = 0; i < n; i++) {
      par[i] = i;
    }
  }
  int find(int x) {
    return par[x] == x ? x: par[x] = find(par[x]);
  }
  bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (siz[x] < siz[y]) swap(x,y);
    siz[x] += siz[y];
    par[y] = x;
    return true;
  }
  bool same(int x, int y) {
    return find(x) == find(y);
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  UF uf(n);
  for (int i = 0; i < m; i++) {
    int t;
    cin >> t;
    int x, y;
    cin >> x >> y;
    if (t) {
      cout << uf.same(x, y) << endl;
    } else {
      uf.unite(x,y);
    }
  }
}
