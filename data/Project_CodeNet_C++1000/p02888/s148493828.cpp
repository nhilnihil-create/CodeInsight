#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  int n;
  cin >> n;
  vector<ll> v(n);
  rep(i, n) cin >> v[i];
  sort(v.begin(), v.end());
  ll ans = 0;
  for (ll i = n - 1; i >= 0; i--) {
    for (ll j = i - 1; j >= 0; j--) {
      auto itr = lower_bound(v.begin(), v.end(), v[i] + v[j]);
      ll d = distance(itr, v.end());
      ans += (n - 1 - i) - d;
    }
  }
  cout << ans << endl;
  return 0;
}