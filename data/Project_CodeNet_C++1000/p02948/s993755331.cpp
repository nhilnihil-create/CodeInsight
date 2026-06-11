#include <bits/stdc++.h>
using namespace std;
using Int = long long;
template <typename T1, typename T2>
inline void chmin(T1 &a, T2 b) {
  if (a > b) a = b;
}
template <typename T1, typename T2>
inline void chmax(T1 &a, T2 b) {
  if (a < b) a = b;
}

int main() {
  Int n, m;
  cin >> n >> m;
  vector<Int> as(n), bs(n);
  for (Int i = 0; i < n; i++) cin >> as[i] >> bs[i];

  vector<vector<Int> > G(m + 1);
  for (Int i = 0; i < n; i++)
    if (as[i] <= m) G[m - as[i]].emplace_back(bs[i]);

  Int ans = 0;
  priority_queue<Int> pq;
  for (Int i = m; i >= 0; i--) {
    for (Int x : G[i]) pq.emplace(x);
    if (!pq.empty()) {
      ans += pq.top();
      pq.pop();
    }
  }
  cout << ans << endl;
  return 0;
}
