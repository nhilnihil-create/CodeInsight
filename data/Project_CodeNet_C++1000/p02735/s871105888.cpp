#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
 
const int N = 110; 
char s[N][N]; 
int n, m; 
int dp[N][N]; 
 
int main() {
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; ++i) 
    scanf("%s", s[i] + 1); 
 
  dp[1][1] = s[1][1] == '#';
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      if(i == 1 && j == 1) continue; 
      dp[i][j] = 1e9; 
      if(s[i][j] == '#') {
        if(i > 1) dp[i][j] = min(dp[i][j], dp[i - 1][j] + (s[i - 1][j] != '#')); 
        if(j > 1) dp[i][j] = min(dp[i][j], dp[i][j - 1] + (s[i][j - 1] != '#')); 
      } else {
        if(i > 1) dp[i][j] = min(dp[i][j], dp[i - 1][j]); 
        if(j > 1) dp[i][j] = min(dp[i][j], dp[i][j - 1]); 
      }
    }
  }
 
  printf("%d\n", dp[n][m]); 
  return 0;
}