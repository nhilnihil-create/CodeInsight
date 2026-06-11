#include <bits/stdc++.h>
#define int long long
using namespace std;

class UnionFind {
private:
  vector<int> data;

  bool isSame(int x, int y) { return find(x) == find(y); }

  bool doUnite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y)
      return (false);
    if (data[x] > data[y])
      swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  int getFind(int k) {
    if (data[k] < 0)
      return (k);
    return (data[k] = find(data[k]));
  }

  int getSize(int k) { return (-data[find(k)]); }

public:
  UnionFind(int N) { data.resize(N, -1); }

  int same(int x, int y) { return isSame(x, y); }
  bool unite(int x, int y) { return doUnite(x, y); }
  int find(int k) { return getFind(k); }
  int size(int k) { return getSize(k); }
};

signed main() {
  int N, M;
  cin >> N >> M;

  UnionFind uf(N);

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    uf.unite(a, b);
  }

  map<int, int> mp;
  for (int i = 0; i < N; i++) {
    mp[uf.find(i)]++;
  }

  int mx = 1;
  for (int i = 0; i < N; i++) {
    mx = max(mx, mp[i]);
  }

  cout << mx << endl;

  return 0;
}