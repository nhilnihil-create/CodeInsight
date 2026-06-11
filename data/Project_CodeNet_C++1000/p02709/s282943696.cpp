#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set

using namespace std;

const ll MOD = 1000000007;
const ll INF = (1LL << 62);

ll dp[2005][2005];

int main() {
  ll N;
  scanf("%lld", &N);

  vector<pair<ll, ll>> list(N);
  for (ll i = 0; i < N; i++) {
    ll v;
    scanf("%lld", &v);
    list[i] = make_pair(v, i);
  }
  sort(list.rbegin(), list.rend());

  for (ll i = 0; i < N; i++) {
    for (ll j = 0; i + j < N; j++) {
      ll val = list[i + j].first;
      ll idx = list[i + j].second;

      // 左
      {
        ll next_idx = i;
        ll plus = abs(idx - next_idx) * val;
        ll new_value = max(dp[i + 1][j], dp[i][j] + plus);
        dp[i + 1][j] = new_value;
        // cout << i << "," << j << "," << plus << "," << dp[i][j] << endl;
      }
      // 右
      {
        ll next_idx = N - 1 - j;
        ll plus = abs(idx - next_idx) * val;
        ll new_value = max(dp[i][j + 1], dp[i][j] + plus);
        dp[i][j + 1] = new_value;
        // cout << i << "," << j << "," << plus << "," << dp[i][j] << endl;
      }
    }
  }

  ll ans = 0;
  for (ll i = 0; i <= N; i++) {
    ans = max(ans, dp[i][N - i]);
  }

  cout << ans << endl;
}
