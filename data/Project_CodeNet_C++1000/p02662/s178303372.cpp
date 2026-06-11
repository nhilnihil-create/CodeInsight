#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ll>;
#define INF 1000000
#define LLINF 10000000000000000ll
#define MOD 998244353LL

bool dbgflag = false;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  vector<vector<ll>>dp(n+1, vector<ll>(s+1));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= s; j++) {
      dp[i][j] = dp[i-1][j] * 2; //元の部分列にi個目を入れても入れなくてもいいが、i個目は和に使わない
      if (j - a[i-1] >= 0) {
        dp[i][j] += dp[i-1][j-a[i-1]];
      }
      dp[i][j] %= MOD;
    }
  }
  cout << dp[n][s] << endl;
}