#include <bits/stdc++.h>

using namespace std;

class UnionFind {
public:
  vector<int> parent;

  UnionFind(int n) : parent(n, -1) {
  }

  int root(int x) {
    if (parent[x] < 0) {
      return x;
    } else {
      return parent[x] = root(parent[x]);
    }
  }

  bool issame(int x, int y) {
    return root(x) == root(y);
  }

  int size(int x) {
    return -parent[root(x)];
  }

  bool unite(int x, int y) {
    int rx = root(x), ry = root(y);
    if (rx == ry) return false;
    if (parent[rx] > parent[ry]) swap(rx, ry);
    parent[rx] += parent[ry];
    parent[ry] = rx;
    return true;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> X(N), Y(N);
  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
  }
  if (N == 1) {
    cout << 1 << '\n';
    return 0;
  }
  int res = N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) continue;
      int dx = X[i] - X[j], dy = Y[i] - Y[j];
      if (dx == 0 && dy == 0) continue;

      UnionFind uf(N);
      for (int a = 0; a < N; a++) {
        for (int b = 0; b < N; b++) {
          if (X[a] - X[b] == dx && Y[a] - Y[b] == dy) {
            uf.unite(a, b);
          }
        }
      }
      int cnt = 0;
      for (int a = 0; a < N; a++) {
        if (uf.root(a) == a) cnt++;
      }
      res = min(res, cnt);
    }
  }
  cout << res << '\n';
  return 0;
}
