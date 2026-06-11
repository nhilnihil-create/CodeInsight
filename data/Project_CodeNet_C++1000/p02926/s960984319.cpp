#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<long double, pair<long long, long long>>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].second.first >> a[i].second.second;
    a[i].first = atan2(a[i].second.second, a[i].second.first);
  }
  sort(a.begin(), a.end());
  long long ans = 0;
  for (int len = 1; len <= n; len++)
    for (int start = 0; start < n; start++) {
      long long x = 0, y = 0;
      for (int i = start, cur = 0; cur < len; i++, i %= n, cur++)
        x += a[i].second.first, y += a[i].second.second;
      ans = max(ans, x * x + y * y);
    }
  cout << setprecision(30) << sqrtl(ans) << '\n';
  return 0;
}