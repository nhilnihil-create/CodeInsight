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
  int N, M;
  cin >> N >> M;
  priority_queue<int> pq;
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    pq.push(A);
  }
  while (M--) {
    int a = pq.top();
    pq.pop();
    pq.push(a / 2);
  }
  long long ans = 0;
  while (!pq.empty()) ans += pq.top(), pq.pop();
  cout << ans << '\n';
  return 0;
}
