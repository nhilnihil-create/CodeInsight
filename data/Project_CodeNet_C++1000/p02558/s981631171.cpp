#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

struct UnionFind {
  vector<int> d;
  UnionFind (int n): d(n,-1) {}
  int find(int x) {
    if(d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if(x == y) return false;
    if(d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y);}
  int size(int x) { return -d[find(x)];}
};

int main() {
  int n, q;
  cin >> n >> q;
  UnionFind uf(n);
  rep(i,q) {
    int t, u, v;
    cin >> t >> u >> v;
    if(t) cout << uf.same(u,v) << endl;
    else uf.unite(u,v);
  }
  return 0;
}