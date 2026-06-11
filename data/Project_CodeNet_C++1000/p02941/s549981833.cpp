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
  ios::sync_with_stdio(0);
  int N;
  cin >> N;
  int A[N], B[N];
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];
  long long ans = 0;
  for (int i = 0; i < N; i++)
    if (A[i] > B[i]) ans = -1;
  if (ans < 0) {
    cout << -1 << '\n';
    return 0;
  }
  auto next = [&](int i) { return (i + 1) % N; };
  auto prev = [&](int i) { return (i - 1 + N) % N; };
  queue<int> que;
  for (int i = 0; i < N; i++) que.push(i);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    if (B[v] <= A[v]) continue;
    int n = next(v), p = prev(v);
    ans += (B[v] - A[v]) / (B[n] + B[p]);
    B[v] = (B[v] - A[v]) % (B[n] + B[p]) + A[v];
    if (B[n] > B[v] + B[next(n)]) que.push(n);
    if (B[p] > B[v] + B[prev(p)]) que.push(p);
  }
  for (int i = 0; i < N; i++)
    if (A[i] != B[i]) ans = -1;
  cout << ans << '\n';
  return 0;
}
