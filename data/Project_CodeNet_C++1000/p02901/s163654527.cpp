#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ll>;
using pis = pair<int, string>;
#define INF 1000000000
#define LLINF 10000000000000000ll
#define MOD 1000000007LL

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;
  vector<ll> keys(m);
  vector<ll> cost(m);
  for (int i = 0; i < m; i++) {
    ll b;
    cin >> cost[i] >> b;
    ll ins = 0, index = 0;
    for (int j = 0; j < b; j++) {
      ll c;
      cin >> c;
      c--;
      ins += (1LL << c);
    }
    keys[i] = ins;
  }
  //for (int i = 0; i < m; i++) cout << keys[i] << " ";
  //cout << endl;

  vector<vector<ll>> dp(m+1, vector<ll>(1<<n, LLINF)); //dp[i][j]: i番目まででjのbitが立っているところの最小コスト

  //dp[0][0] = 0;
  for (int i = 0; i < m; i++) {
    dp[i][0] = 0;
    for (int j = 0; j < (1<<n); j++) {
      if (dp[i][j] != LLINF) {
        dp[i+1][j | keys[i]] = min(dp[i][j] + cost[i], min(dp[i][j | keys[i]], dp[i+1][j | keys[i]]));
        dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
      }
    }
  }
  /*for (int i = 0; i < m+1; i++) {
    for (int j = 0; j < 1<<n; j++) cout << dp[i][j] << " ";
    cout << endl;
  }*/
  cout << ((dp[m][(1<<n) -1] == LLINF) ? -1 : dp[m][(1<<n) -1]) << endl;
}
