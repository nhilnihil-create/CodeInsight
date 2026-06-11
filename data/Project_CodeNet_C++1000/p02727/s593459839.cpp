#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;
  vector<int> p(a), q(b), r(c);
  rep(i, 0, a) cin >> p[i];
  rep(i, 0, b) cin >> q[i];
  rep(i, 0, c) cin >> r[i];
  sort(p.rbegin(), p.rend());
  sort(q.rbegin(), q.rend());
  sort(r.rbegin(), r.rend());

  priority_queue<int> pq;
  rep(i, 0, x) pq.push(p[i]);
  rep(i, 0, y) pq.push(q[i]);
  rep(i, 0, c) pq.push(r[i]);

  ll ans = 0;
  rep(i, 0, x + y) {
    int t = pq.top();
    pq.pop();
    ans += t;
  }
  cout << ans << endl;
}
