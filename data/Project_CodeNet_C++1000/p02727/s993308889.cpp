#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

int main() {
  int x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;
  V<ll> p(a), q(b), r(c);
  rep(i, a) cin >> p[i];
  rep(i, b) cin >> q[i];
  rep(i, c) cin >> r[i];

  sort(p.rbegin(), p.rend());
  sort(q.rbegin(), q.rend());
  priority_queue<ll, V<ll>, greater<ll>> que;
  rep(i, x) que.push(p[i]);
  rep(i, y) que.push(q[i]);

  sort(r.rbegin(), r.rend());
  int l = min(c, x + y);
  rep(i, l) {
    if (r[i] <= que.top()) break;
    que.pop();
    que.push(r[i]);
  }
  ll ans = 0;
  while (!que.empty()) {
    ans += que.top();
    que.pop();
  }
  cout << ans << endl;
}
