#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 300 + 5;
const ll inf = 1e14;

int n, k;
ll a[N], dp[N][N];

void init() {
  cin >> n >> k;
  for(int i = 1 ; i <= n ; ++i) cin >> a[i];
  a[0] = 0;
}
void solve() {
  ll mn = inf;
  for(int i = 0 ; i <= n ; ++i) {
    for(int j = 0 ; j <= n ; ++j) {
      dp[i][j] = inf;
    }
  }
  dp[0][0] = 0;
  for(int i = 1 ; i <= n ; ++i) {
    for(int j = 1 ; j <= i ; ++j) {
      for(int l = 0 ; l < i ; ++l) dp[i][j] = min(dp[i][j], dp[l][j - 1] + max(0LL, a[i] - a[l]));
    }
  }
  for(int i = 0 ; i <= n ; ++i) mn = min(mn, dp[i][n - k]);
  cout << mn << '\n';
}

int main() {
  init();
  solve();
}
