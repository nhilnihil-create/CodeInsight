#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int N = 1024, INF = 1e8;

int n, a[N][N];

int b[N][N]; // iがjと試合を行なうのはb[i][j]番目(0-indexed)
int dp[N][N]; // dp[i][j]: iがj人と試合を行なうまでの最短日数
bool seen[N][N];

int rec(int i, int j) {
  if (dp[i][j] != -1) return dp[i][j];
  if (seen[i][j]) return INF;
  seen[i][j] = true;
  if (j == 0) return dp[i][0] = 0;
  int op = a[i][j - 1];
  return dp[i][j] = max(rec(i, j - 1), rec(op, b[op][i])) + 1;
}

int main() {
  cin >> n;
  rep(i, n) rep(j, n-1) cin >> a[i][j];
  rep(i, n) rep(j, n-1) a[i][j]--;
  rep(i, n) rep(j, n-1) b[i][a[i][j]] = j;
  rep(i, n) rep(j, n) dp[i][j] = -1;
  rep(i, n) rep(j, n) seen[i][j] = false;
  int ans = 0;
  rep(i, n) ans = max(ans, rec(i, n-1));
  if (ans >= INF) ans = -1;
  cout << ans << endl; 
  return 0;
}