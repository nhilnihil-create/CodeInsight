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
  int N;
  cin >> N;
  vector<vector<pair<int, int>>> tree(N);
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    tree[a].emplace_back(b, i);
    tree[b].emplace_back(a, i);
  }
  int K = 0;
  for (int i = 0; i < N; i++) K = max(K, (int)tree[i].size());
  int c[N - 1];
  fill(c, c + N - 1, -1);
  function<void(int, int, int)> dfs = [&](int v, int p, int color) {
    int cnum = 1;
    for (auto e : tree[v])
      if (e.first != p) {
        if (cnum == color) cnum++;
        c[e.second] = cnum;
        dfs(e.first, v, cnum);
        cnum++;
      }
  };
  dfs(0, -1, -1);
  cout << K << '\n';
  for (int i = 0; i < N - 1; i++) cout << c[i] << '\n';
  return 0;
}
