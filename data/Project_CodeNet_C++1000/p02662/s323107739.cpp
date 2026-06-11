#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)
ll dp[3005][3005];
const int M = 998244353;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  dp[0][0] = 1;
  rep(i, n) for (int j = 0; j <= s; ++j) {
    dp[i+1][j] = dp[i][j]*2%M;
    if (j >= a[i]) dp[i+1][j] = (dp[i+1][j]+dp[i][j-a[i]])%M;
  }
  cout << dp[n][s] << endl;
}