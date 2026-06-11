#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int dp[5005][5005]; // グローバルで定義すると0で初期化される

int main() {
  // dp[i][j] i文字目とj文字目から連続する文字列の長さ
  // 重なった分は最後に考慮、0-indexed
  int N;
  cin >> N;
  string S;
  cin >> S;
  for (int j = N-1; j >= 0; j--) {
    for (int i = j; i >= 0; i--) {
      if (S[i] != S[j]) dp[i][j] = 0;
      else dp[i][j] = dp[i+1][j+1] + 1;
    }
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i+1; j < N; j++) {
      int temp = min(dp[i][j], j-i);
      ans = max(ans, temp);
    }
  }
  cout << ans << '\n';
  return 0;
}