# include <sstream>
# include <stack>
# include <string>
# include <vector>
# include <iomanip>
# include <iostream>
# define rep(i, n) for (int i = 0; i < (int)(n); i++)
# define irep(i, n) for (int i = int(n) - 1; i >= 0; i--)
# define FOR(i, m, n) for (int i = int(m); i < (int)(n); i++)

using namespace std;

int main(){
  int N,W;
  int v[1005];
  int w[1005];
  int dp[1005][1005];
  cin >> N >> W;
  rep(i, N){
    cin >> v[i] >> w[i];
  }

  irep(i, N+1){
    rep(j,W+1){
      if(i == N){
        dp[i][j] = 0;
      }
      if(j == 0){
        dp[i][j] = 0;
      }
      if(j - w[i] > -1){
        if(dp[i+1][j-w[i]]+v[i] > dp[i+1][j]){
          dp[i][j] = dp[i+1][j-w[i]]+v[i];
        }else{
          dp[i][j] = dp[i+1][j];
        }
      }else{
        dp[i][j] = dp[i+1][j];
      }
    }
  }
  cout << dp[0][W] << endl;
}