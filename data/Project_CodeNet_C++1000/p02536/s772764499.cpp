#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> par;

    UnionFind(int N) : par(N) {
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        par[rx] = ry;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};


int main() {
  long n, m;
  cin >> n >> m;
  long a[m], b[m];
  UnionFind tree(n);
  
  for (long i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
    tree.unite(a[i]-1, b[i]-1);
  }
  
  long cnt = 0;
  for (long i = 0; i < n; i++) {
    if (!tree.same(0, i)) {
      tree.unite(0, i);
      cnt++;
    }
  }
  
  cout << cnt;
  
  return 0;
}