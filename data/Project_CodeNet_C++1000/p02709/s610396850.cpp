#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N; cin >> N;
  vector<pair<ll, ll>> P(N);
  for (ll i = 0; i < N; i++) {
    ll a; cin >> a;
    P[i] = make_pair(a, i);
  }
  sort(P.rbegin(), P.rend());

  ll INF = 1e18;
  vector<ll> dp(N + 1, 0);
  for (ll i = 0; i < N; i++) {
    vector<ll> dp2 = dp;
    for (ll l = 0; l <= i + 1; l++) {
      ll r = N - (i - l);
      if (l > 0) dp2[l] = max(dp2[l], dp[l - 1] + P[i].first * abs(l - 1 - P[i].second));
      if (r <= N) dp2[l] = max(dp2[l], dp[l] + P[i].first * abs(r - 1 - P[i].second));
    }
    dp = dp2;
  }

  ll ans = *max_element(dp.begin(), dp.end());
  cout << ans << '\n';
  return 0;
}