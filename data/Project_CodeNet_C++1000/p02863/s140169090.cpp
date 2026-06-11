#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll N, T;
  cin >> N >> T;
  vector<pll> AB(N);
  for (ll i = 0; i < N; ++i) {
    cin >> AB.at(i).first >> AB.at(i).second;
  }
  sort(AB.begin(), AB.end(), [] (pll A, pll B) {
    return A.first < B.first;
  });
  vector<ll> dp(T + 1, 0);
  for (ll i = 0; i < N; ++i) {
    ll a = AB.at(i).first, b = AB.at(i).second;
    vector<ll> temp_dp = dp;
    for (ll j = 0; j < T; ++j) {
      ll now = dp.at(j);
      ll check = min(T, j + a);
      temp_dp.at(check) = max(dp.at(check), now + b);
    }
    dp = temp_dp;
  }
  ll ans = dp.at(T);
  // for (ll i = 0; i <= T; ++i) {
  //   ans = max(ans, dp.at(i));
  // }
  cout << ans << "\n";
  // for (ll i = 0; i <= T; ++i) {
  //   cout << i << ' ' << dp.at(i) << "\n";
  // }
}
