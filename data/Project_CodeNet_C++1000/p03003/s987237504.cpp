#include <algorithm>
#include <iostream>

using namespace std;

const int M = 1e9+7;
int n, m;
int s[2200];
int t[2200];
long long dp[2200][2200];
long long sum[2200][2200];

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> t[i];
  }
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i-1] == t[j-1]) {
        dp[i][j] = (sum[i-1][j-1] + 1) % M;
      }
      sum[i][j] += (sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + dp[i][j] + M) % M;
    }
  }
  
  cout << (sum[n][m] + 1) % M << endl;
  return 0;
}