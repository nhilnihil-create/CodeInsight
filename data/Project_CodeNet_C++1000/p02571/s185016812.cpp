#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl

void solve() {
  string s1, s2;
  cin >> s1 >> s2;
  ll n = s1.length();
  ll m = s2.length();
  ll ans = LLONG_MAX;
  for (int i = 0; i <= n - m; i++) {
    ll diff = 0;
    ll temp = i;
    for (int j = 0; j < m; j++) {
      diff += (s1[temp] != s2[j]);
      temp++;
    }
    ans = min(ans, diff);
  }
  cout << ans;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ll test = 1;
  // cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
