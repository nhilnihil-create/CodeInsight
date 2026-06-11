#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ll>;
using pis = pair<int, string>;
#define all(x) (x).begin(), (x).end()
#define INF 1000000000
#define LLINF 10000000000000000ll
#define MOD 1000000007

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  //cout << fixed << setprecision(15)

  string s;
  cin >> s;
  int len = s.size(), div = 13, tens = 1;
  vector<vector<ll>> dp(len+1, vector<ll>(div, 0)); //dp[i][j]: 下からi文字目までで余りjであるような個数
  dp[0][0] = 1;
  for (int i = 1; i < len+1; i++) {
    for (int j = 0; j < div; j++) {
      if (s[len-i] != '?') {
        dp[i][((int)(s[len-i] - '0') * tens + j) % div] = dp[i-1][j];
      }
      else {
        for (int k = 0; k < 10; k++) {
          dp[i][(k * tens + j) % div] += dp[i-1][j];
          dp[i][(k * tens + j) % div] %= MOD;
        }
      }
    }
    tens = (tens * 10) % div;
  }

  cout << dp[len][5] << endl;
}
