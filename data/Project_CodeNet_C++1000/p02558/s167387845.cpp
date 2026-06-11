#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;

struct UnionFind {
  vector<int> par;  // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
  vector<int> rank;

  UnionFind(int N) : par(N), rank(N) {  //最初は全てが根であるとして初期化
    for (int i = 0; i < N; i++) {
      par[i] = i;
      rank[i] = 0;
    }
  }

  int root(int x) {
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
  }

  void unite(int x, int y) {  // xとyの木を併合
    x = root(x);
    y = root(y);
    if (x == y) return;

    if (rank[x] < rank[y]) {
      par[x] = y;
    } else {
      par[y] = x;
      if (rank[x] == rank[y]) rank[x]++;
    }
  }

  bool same(int x, int y) {  // 2つのデータx, yが属する木が同じならtrueを返す
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }
};

int main() {
  int n, q;
  cin >> n >> q;

  UnionFind u(n);

  for (int i = 0; i < q; i++) {
    int p, a, b;
    cin >> p >> a >> b;
    if (p == 0) {
      u.unite(a, b);
    } else {
      cout << (u.same(a, b) ? 1 : 0) << endl;
    }
  }
}