#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int N = 3000, T = 3000;

int n, t, a[N + 1], b[N + 1];

int dp1[N + 2][T]; // 1-i
int dp2[N + 2][T]; // i-n

int main() {
  cin >> n >> t;
  for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
  rep(i, n+2) rep(j, t) dp1[i][j] = 0;
  rep(i, n+2) rep(j, t) dp2[i][j] = 0;
  
  for (int i = 1; i <= n; i++) rep(j, t) {
    dp1[i][j] = max(dp1[i][j], dp1[i - 1][j]);
    if (j - a[i] >= 0) dp1[i][j] = max(dp1[i][j], dp1[i - 1][j - a[i]] + b[i]);
  }

  for (int i = n; i >= 1; i--) rep(j, t) {
    dp2[i][j] = max(dp2[i][j], dp2[i + 1][j]);
    if (j - a[i] >= 0) dp2[i][j] = max(dp2[i][j], dp2[i + 1][j - a[i]] + b[i]);
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) rep(j, t) {
    ans = max(ans, dp1[i - 1][j] + dp2[i + 1][t - 1 - j] + b[i]);
  }
  cout << ans << endl;
  return 0;
}