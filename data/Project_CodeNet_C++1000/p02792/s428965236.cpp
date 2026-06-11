#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
typedef  long long ll;
typedef pair<int, int> p;

int dp[10][10];
//vector<vector<int>> dp(10, vector<int>(10));

int main() {
  int N;
  cin >> N;
  ll ans = 0;
  rep(i, 10) rep(j, 10) dp[i][j] = 0;
  for (int i = 1; i < N+1; i++) {
    int back = i % 10;
    int j = i;
    while (j >= 10) {
      j /= 10;
    }
    int top = j;
    dp[top][back]++;
  }
  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      ans += dp[i][j] * dp[j][i];
    }
  }
  cout << ans << '\n';
  return 0;
}
