#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int n, h;
int a[1010], b[1010];
ll dp[10010];
int main() {
  cin >> h >> n;
  rep(i,n) {
    cin >> a[i] >> b[i];
  }
  rep(i,10010) dp[i] = INF;
  dp[h] = 0;
  for (int i = h; i >= 0; i--)
  {
    rep(j,n) {
      if (i >= a[j]) dp[i-a[j]] = min(dp[i-a[j]], dp[i]+b[j]);
      else dp[0] = min(dp[0], dp[i]+b[j]);
    }
  }
  cout << dp[0] << endl;
  return 0;
}