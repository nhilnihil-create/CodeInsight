#include <bits/stdc++.h>
using namespace std;

using ll = long long;
static const ll MOD = 1e9 + 7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n, m;
  cin >> n >> m;
  
  vector<int> s(n), t(m);
  for (int i = 0; i < n; i++) cin >> s.at(i);
  for (int i = 0; i < m; i++) cin >> t.at(i);
  
  vector<vector<ll>> dp(n + 1, vector<ll>(m + 1)), sum(n + 1, vector<ll>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s.at(i - 1) == t.at(j - 1)) dp.at(i).at(j) = sum.at(i - 1).at(j - 1) + 1;
      else dp.at(i).at(j) = 0;
      dp.at(i).at(j) %= MOD;
      sum.at(i).at(j) = sum.at(i).at(j - 1) + sum.at(i - 1).at(j) - sum.at(i - 1).at(j - 1) + dp.at(i).at(j) + MOD;
      sum.at(i).at(j) %= MOD;
    }
  }
  
  cout << (sum.at(n).at(m) + 1) % MOD << '\n';
}