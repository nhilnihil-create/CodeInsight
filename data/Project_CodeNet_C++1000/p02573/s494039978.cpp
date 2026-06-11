#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;

struct UnionFind {
  vector<int> par;  // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
  vector<int> rank;
  vector<int> siz;

  UnionFind(int N)
      : par(N), rank(N), siz(N) {  //最初は全てが根であるとして初期化
    for (int i = 0; i < N; i++) {
      par[i] = i;
      rank[i] = 0;
      siz[i] = 1;
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

    if (siz[x] < siz[y]) swap(x, y);
    siz[x] += siz[y];
    par[y] = x;
    return;
  }

  bool same(int x, int y) {  // 2つのデータx, yが属する木が同じならtrueを返す
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }

  int size(int x) { return siz[root(x)]; }
};

int main() {
  int n, m;
  cin >> n >> m;
  UnionFind u(n);

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    u.unite(x, y);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, u.size(i));
  }

  cout << ans << endl;
}