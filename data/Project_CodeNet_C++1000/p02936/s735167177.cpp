#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
#ifdef __LOCAL
#define debug(x) cerr << __LINE__ << ": " << #x << " = " << x << endl
#define debugArray(x, n)                           \
  cerr << __LINE__ << ": " << #x << " = {";        \
  for (long long hoge = 0; (hoge) < (n); ++(hoge)) \
    cerr << ((hoge) ? "," : "") << x[hoge];        \
  cerr << "}" << endl
#else
#define debug(x) (void(0))
#define debugArray(x, n) (void(0))
#endif

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, Q;
  cin >> N >> Q;
  vector<vector<int>> tree(N);
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  long long val[N];
  fill(val, val + N, 0);
  while (Q--) {
    int p;
    long long x;
    cin >> p >> x;
    val[--p] += x;
  }
  function<void(int, int)> dfs = [&](int v, int p) {
    for (int u : tree[v])
      if (u != p) {
        val[u] += val[v];
        dfs(u, v);
      }
  };
  dfs(0, -1);
  for (int i = 0; i < N; i++) cout << val[i] << (i == N - 1 ? '\n' : ' ');
  return 0;
}
