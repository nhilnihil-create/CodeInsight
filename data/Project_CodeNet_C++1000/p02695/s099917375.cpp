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
  int N, M, Q;
  cin >> N >> M >> Q;
  int a[Q], b[Q], c[Q];
  long long d[Q];
  for (int i = 0; i < Q; i++)
    cin >> a[i] >> b[i] >> c[i] >> d[i], a[i]--, b[i]--;
  vector<vector<int>> cand;
  function<void(int, vector<int> &)> rec = [&](int i, vector<int> &A) {
    if (i == N) {
      cand.push_back(A);
    } else {
      for (int j = A.size() ? A.back() : 1; j <= M; j++) {
        A.push_back(j);
        rec(i + 1, A);
        A.pop_back();
      }
    }
  };
  vector<int> tmp;
  rec(0, tmp);
  long long ans = 0;
  for (auto A : cand) {
    long long score = 0;
    for (int i = 0; i < Q; i++) {
      if (A[b[i]] - A[a[i]] == c[i]) score += d[i];
    }
    ans = max(ans, score);
  }
  cout << ans << endl;
  return 0;
}
