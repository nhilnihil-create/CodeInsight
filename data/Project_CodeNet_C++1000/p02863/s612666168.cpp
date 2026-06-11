#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ll>;
#define INF 1000000000
#define LLINF 10000000000000000ll
#define MOD 1000000007LL

bool dbgflag = false;


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, t;
  cin >> n >> t;
  vector<pll> food(n);
  for (int i = 0; i < n; i++) cin >> food[i].first >> food[i].second;
  sort(food.begin(), food.end());
  //cout << "sort" << endl;

  vector<vector<ll>> dp(n+1, vector<ll>(t+1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= t; j++) {
      dp[i][j] =  max(dp[i-1][j], dp[i][j-1]);
      if (j >= food[i-1].first) dp[i][j] = max(dp[i][j], dp[i-1][j-food[i-1].first] + food[i-1].second);
    }
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, dp[i-1][t-1] + food[i-1].second);
  }
  cout << ans << endl;
}
