#include <bits/stdc++.h>
#include <iomanip>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll dp[2000][2001];

int main() {
  int n;
  cin >> n;
  vector<pair<ll, ll> > a(n);
  rep(i, n) {a[i].second = i; cin >> a[i].first;}
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  dp[0][0] = a[0].first * (n-1 - a[0].second);
  dp[0][1] = a[0].first * a[0].second;
  for (int i=1; i<n; i++) for (int j=0; j<=i+1; j++) {
    if (i+1 == j) dp[i][j] = dp[i-1][j-1] + a[i].first * (a[i].second - j + 1);
    else if (j == 0) dp[i][j] = dp[i-1][0] + a[i].first * (n-1-i - a[i].second);
    else dp[i][j] = max(dp[i-1][j] + a[i].first * (n-1-i+j - a[i].second),
                        dp[i-1][j-1] + a[i].first * (a[i].second - j + 1));
  }
  ll ans = 0; 
  rep(i, n+1) if (ans < dp[n-1][i]) ans = dp[n-1][i];
  cout << ans << endl;
  return 0;
}