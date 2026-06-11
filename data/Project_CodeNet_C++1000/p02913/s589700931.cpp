#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int N = 5005;

int n;
string s;

int dp[N][N];

int main() {
  cin >> n >> s;
  for (int i = n-1; i >= 0; i--) {
    for (int j = n-1; j >= 0; j--) {
      if (s[i] != s[j]) dp[i][j] = 0;
      else if (i == n-1 || j == n-1) dp[i][j] = 1;
      else dp[i][j] = dp[i+1][j+1] + 1;
    }
  }
  int mal = 0;
  rep(i, n) rep(j, n) {
    mal = max(mal, min(dp[i][j], abs(i-j)));
  }
  cout << mal << endl;
  return 0;
}