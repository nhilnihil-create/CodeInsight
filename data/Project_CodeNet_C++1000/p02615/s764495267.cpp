#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) {
    cin >> a[i];
  }
  sort(a.begin(), a.end(), greater<int>());
  vector<ll> c(1, a[0]);
  for (int i = 1; i < n; i++) {
    c.emplace_back(a[i]);
    c.emplace_back(a[i]);
  }
  ll ans = 0;
  rep(i, n - 1) {
    ans += c[i];
  }
  cout << ans << '\n';
  return 0;
}
