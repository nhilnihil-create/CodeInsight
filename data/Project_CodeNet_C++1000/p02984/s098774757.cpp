#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  using ll = long long;
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto&& e : a) {
    cin >> e;
    e *= 2;
  }
  auto judge = [&](ll rain0) {
    vector<ll> rain(n + 1);
    rain[0] = rain0;
    for (int i = 0; i < n; i++) {
      rain[i + 1] = a[i] - rain[i];
    }
    if (rain[0] == rain[n]) {
      return 0;
    } else if (rain[0] > rain[n]) {
      return 1;
    } else {
      return -1;
    }
  };
  ll ans0;
  ll upper = 2 * (ll)1e9 + 1;
  ll lower = -1;
  while (true) {
    ll mid = upper + (lower - upper) / 2;
    if (judge(mid) == 0) {
      ans0 = mid;
      break;
    } else if (judge(mid) == 1) {
      upper = mid;
    } else {
      lower = mid;
    }
  }
  vector<ll> ans(n);
  ans[0] = ans0;
  cout << ans[0];
  for (int i = 0; i < n - 1; i++) {
    ans[i + 1] = a[i] - ans[i];
    cout << ' ' << ans[i + 1];
  }
  cout << '\n';
  return 0;
}
