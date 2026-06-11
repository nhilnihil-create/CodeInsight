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
  vector<vector<ll>> dp1(N, vector<ll>(T, 0));
  vector<vector<ll>> dp2(N, vector<ll>(T, 0));
  for (ll i = 0; i < N - 1; ++i) {
    ll a = AB.at(i).first, b = AB.at(i).second;
    for (ll j = 0; j < T; ++j) {
      if (j != 0) {
        dp1.at(i).at(j) = max(dp1.at(i).at(j), dp1.at(i).at(j - 1));
      }
      if (i != 0) {
        dp1.at(i).at(j) = max(dp1.at(i - 1).at(j), dp1.at(i).at(j));
      }
      if (a + j >= T) {
        continue;
      }
      ll now = dp1.at(i).at(j);
      dp1.at(i + 1).at(j + a) = max(dp1.at(i + 1).at(j + a), now + b);
    }
  }
  for (ll i = N - 1; i > 0; --i) {
    ll a = AB.at(i).first, b = AB.at(i).second;
    for (ll j = 0; j < T; ++j) {
      if (j != 0) {
        dp2.at(i).at(j) = max(dp2.at(i).at(j), dp2.at(i).at(j - 1));
      }
      if (i != N - 1) {
        dp2.at(i).at(j) = max(dp2.at(i + 1).at(j), dp2.at(i).at(j));
      }
      if (a + j >= T) {
        continue;
      }
      ll now = dp2.at(i).at(j);
      dp2.at(i - 1).at(j + a) = max(dp2.at(i - 1).at(j + a), now + b);
    }
  }
  ll ans = 0;
  for (ll i = 0; i < N; ++i) {
    for (ll j = 0; j < T; ++j) {
      ans = max(ans, dp1.at(i).at(j) + dp2.at(i).at(T - j - 1) + AB.at(i).second);
    }
  }
  cout << ans << "\n";
  // for (ll i = 0; i < N; ++i) {
  //   for (ll j = 0; j < T; ++j) {
  //     cout << dp1.at(i).at(j) << " ";
  //   }
  //   cout << "\n";
  // }
}
