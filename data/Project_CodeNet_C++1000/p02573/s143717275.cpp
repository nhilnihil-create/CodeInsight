#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct UnionFind
{
  //自身が親であれば、その集合に属する頂点数に-1を掛けたもの
  //そうでなければ親のid
  vector<int> r;

  UnionFind(int N)
  {
    r = vector<int>(N, -1);
  }

  int root(int x)
  {
    if (r[x] < 0)
      return x;
    return r[x] = root(r[x]);
  }

  bool unite(int x, int y)
  {
    x = root(x);
    y = root(y);
    if (x == y)
      return false;
    if (r[x] > r[y])
      swap(x, y);
    r[x] += r[y];
    r[y] = x;
    return true;
  }

  int size(int x)
  {
    return -r[root(x)];
  }
};

int main()
{
  int N, M;

  cin >> N >> M;
  UnionFind tree(N);

  for (int i = 0; i < M; i++)
  {
    int a, b;
    cin >> a >> b;
    a -= 1;
    b -= 1;
    tree.unite(a, b);
  }

  //最大の友達集合を求める
  int ans = 0;
  for (int i = 0; i < N; i++)
  {
    ans = max(ans, tree.size(i));
  }

  cout << ans << endl;
}