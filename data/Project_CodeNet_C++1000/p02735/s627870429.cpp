#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef vector<ll> vl;
const int MN = 112;
const int inf = 1e9;
int n, m, dp[MN][MN];
char s[MN][MN];

int ds (int i, int j) {
  if (dp[i][j] != -1) return dp[i][j];
  int res = inf;
  if (i+1 < n) {
    if (s[i][j] == '#') {
      if (s[i+1][j] == '#') {
        res = min(res, ds(i+1,j));
      } else {
        res = min(res, ds(i+1,j)+1);
      }
    } else {
      res = min(res, ds(i+1,j));
    }
  }
  if (j+1 < m) {
    if (s[i][j] == '#') {
      if (s[i][j+1] == '#') {
        res = min(res, ds(i,j+1));
      } else {
        res = min(res, ds(i,j+1)+1);
      }
    } else {
      res = min(res, ds(i,j+1));
    }
  }
  return dp[i][j] = res;
}

int main (void) {
  ios::sync_with_stdio(false);cin.tie(0);
  cout << fixed << setprecision(15);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> s[i];
  memset(dp,-1,sizeof(dp));
  dp[n-1][m-1] = s[n-1][m-1] == '#';
  cout << ds(0,0) << '\n';
  return 0;
}

