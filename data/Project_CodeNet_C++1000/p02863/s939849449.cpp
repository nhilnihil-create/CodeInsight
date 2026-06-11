//解説あり
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define all(v) (v).begin(), (v).end()


using namespace std;

typedef long long ll;

static const long long MOD = 1000000007;

int a[3005], b[3005], t, n;
int dp1[3005][3005], dp2[3005][3005];

int main(void) {
  cin >> n >> t;
  rep(i, 1, n+1) scanf("%d %d", &a[i], &b[i]);

  //両側DP

// 1〜iまでの料理を食べた時の最大値
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=t-1; j++) {
      if (j-a[i]<0) dp1[i][j] = dp1[i-1][j];
      else dp1[i][j] = max(dp1[i-1][j], dp1[i-1][j-a[i]]+b[i]);
    }
  }

  // i〜nまでの料理を食べた時の最大値
  for (int i=n; i>=1; i--) {
    for (int j=1; j<=t-1; j++) {
      if (j-a[i]<0) dp2[i][j] = dp2[i+1][j];
      else dp2[i][j] = max(dp2[i+1][j], dp2[i+1][j-a[i]]+b[i]);
    }
  }

  int ans = -1;
  for (int i=1; i<=n; i++) {
    for (int j=0; j<=t-1; j++) {
      ans = max(ans, dp1[i-1][j] + b[i] + dp2[i+1][t-1-j]);
    }
  }
    

    cout << ans << endl;

	return 0;
}
