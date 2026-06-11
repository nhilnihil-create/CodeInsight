#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define pll pair<ll, ll>
#define vll vector<ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);
// const ll INF = 99;

pll keys[1005];

ll dp[15][(2LL << 15LL)];

int main() {
  fill(dp[0], dp[14], INF);
  dp[0][0] = 0;

  ll N, M;
  scanf("%lld %lld", &N, &M);

  for (ll i = 0; i < M; i++) {
    ll a, b;
    scanf("%lld %lld", &a, &b);

    ll capability = 0;
    for (ll j = 0; j < b; j++) {
      ll t;
      scanf("%lld", &t);
      capability |= 1LL << (t - 1);
    }
    keys[i].first = a;
    keys[i].second = capability;

    // cout << a << " " << capability << endl;
  }

  for (ll i = 0; i < N; i++) {
    ll box = (i + 1);

    for (ll status = 0; status < (2LL << (N - 1)); status++) {
      for (ll k = 0; k < M; k++) {
        dp[i + 1][status] = min(dp[i + 1][status], dp[i][status]);
        ll next_value = dp[i][status] + keys[k].first;
        ll next_status = status | keys[k].second;
        dp[i + 1][next_status] = min(dp[i + 1][next_status], next_value);

        // cout << "dp[i + 1][next_status]:" << dp[i + 1][next_status] << endl;
        // cout << "next_value:" << next_value << endl;
        // cout << "next_status:" << next_status << endl;
      }
    }
    // cout << i << endl;
  }

  // for (ll i = 0; i <= N; i++) {
  //   for (ll j = 0; j < (2LL << (N - 1)); j++) {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << "" << endl;
  // }

  ll ans = dp[N][(1LL << N) - 1LL];
  if (ans == INF) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}
