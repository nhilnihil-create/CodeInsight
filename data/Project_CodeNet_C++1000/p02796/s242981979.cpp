#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<pii> r(n);
  for (int i = 0; i < n; i++) {
    int x, l;
    cin >> x >> l;
    r[i].first = x + l;
    r[i].second = x - l;
  }
  sort(r.begin(), r.end());
  int ans = 0, border = -(1 << 30);
  for (auto p : r) {
    int a, b;
    tie(b, a) = p;
    if (a >= border) {
      ans += 1;
      border = b;
    }
  }
  cout << ans << '\n';
}