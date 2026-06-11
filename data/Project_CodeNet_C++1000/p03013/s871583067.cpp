#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
const ll mod = 1e9 + 7;
int main() {
  int n, m;
  cin >> n >> m;
  vector<bool> ng(n, false);

  for (int i = 0; i < m; i++) {
    int temp;
    cin >> temp;
    ng[temp] = true;
  }

  vector<ll> dp(n + 1, 0LL);
  dp[0] = 1;
  dp[1] = ng[1] ? 0 : 1;

  for (int i = 0; i < n - 1; i++) {
    if (ng[i]) dp[i] = 0;
    if (ng[i + 1]) dp[i + 1] = 0;

    dp[i + 2] = dp[i + 1] % mod + dp[i] % mod;
    dp[i + 2] %= mod;
  }

  cout << dp[n] << endl;
}