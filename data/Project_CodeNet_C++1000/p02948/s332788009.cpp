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
  pair<int, long long> AB[N];
  for (int i = 0; i < N; i++) cin >> AB[i].first >> AB[i].second;
  sort(AB, AB + N);
  long long ans = 0;
  priority_queue<long long> pq;
  int j = 0;
  for (int i = min(M, N) - 1; i >= 0; i--) {
    while (j < N && i + AB[j].first <= M) pq.push(AB[j++].second);
    if (!pq.empty()) {
      ans += pq.top();
      pq.pop();
    }
  }
  cout << ans << '\n';
  return 0;
}
