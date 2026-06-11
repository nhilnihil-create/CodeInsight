#include <bits/stdc++.h>

#define nl '\n'

using namespace std;

typedef long long ll;

void solve() {
  int S;
  cin >> S;
  const int mod = 1e9 + 7;

  vector<ll> dp(S + 1);
  dp[0] = 1;
  for (int i = 3; i <= S; i++) {
    for (int j = 3; j <= i; j++)
      dp[i] = (dp[i] + dp[i-j]) % mod;
  }

  cout << dp[S];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  // int t;
  // cin >> t;
  // while (t--) {
    solve();
    cout << nl;
  // }

  return 0;
}