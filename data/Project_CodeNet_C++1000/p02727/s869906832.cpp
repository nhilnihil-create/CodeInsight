#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;
  vector<int> p(a), q(b), r(c);
  for (auto&& e : p) {
    cin >> e;
  }
  for (auto&& e : q) {
    cin >> e;
  }
  for (auto&& e : r) {
    cin >> e;
  }
  sort(p.begin(), p.end(), greater<int>());
  sort(q.begin(), q.end(), greater<int>());
  for (int i = 0; i < x; i++) {
    r.emplace_back(p[i]);
  }
  for (int i = 0; i < y; i++) {
    r.emplace_back(q[i]);
  }
  sort(r.begin(), r.end(), greater<int>());
  ll ans = 0;
  for (int i = 0; i < x + y; i++) {
    ans += r[i];
  }
  cout << ans << '\n';
  return 0;
}
