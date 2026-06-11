#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr int INF = 2e9;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  vector<ll> dp(n + 1, 0);

  dp[0] = 1000;

  for (int i = 0; i < n; i++) {
    dp[i + 1] = dp[i];
    for (int j = 0; j <= i; j++) {
      dp[i + 1] = max(dp[i + 1], (dp[j] / a[j]) * a[i] + dp[j] % a[j]);
    }
  }
  cout << dp[n] << endl;
  return 0;
} 