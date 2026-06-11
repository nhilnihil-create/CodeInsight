#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
const int maxN = 2e3 + 10;
const ll inf = 1e18;

int n;
pair<ll, int> a[maxN];
ll dp[maxN][maxN];

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//  freopen("abc.inp", "r", stdin); freopen("abc.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].F;
    a[i].S = i;
  }
  sort(a+1, a+n+1, greater<pair<ll,int> >());

  for (int i = 0; i < maxN; ++i)
    for (int j = 0; j < maxN; ++j)
      dp[i][j] = -inf;

  dp[0][0] = 0;
  ll ans = 0;
  for (int i = 0; i <= n; ++i)
  for (int j = 0; i + j <= n; ++j) {
    int k = i + j;
    if (k == n) {
      ans = max(ans, dp[i][j]);
      continue;
    }
    dp[i+1][j] = max(dp[i+1][j], dp[i][j] + a[k+1].F * abs(a[k+1].S - (i+1)) );
    dp[i][j+1] = max(dp[i][j+1], dp[i][j] + a[k+1].F * abs((n-j) - a[k+1].S) );
  }

  cout << ans;
  return 0;
}
