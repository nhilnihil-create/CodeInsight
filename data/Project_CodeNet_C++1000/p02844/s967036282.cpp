#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<vector<vector<bool>>> dp(n+1,vector<vector<bool>>(4,vector<bool>(1000)));
  dp[0][0][0] = 1;
  rep(i,n){
    rep(j,4){
      rep(k,1000){
        if(dp[i][j][k]){
          dp[i+1][j][k] = 1;
          if(j < 3){
          	dp[i+1][j+1][10*k+s[i]-'0'] = 1;
          }
        }
      }
    }
  }
  int ans = 0;
  rep(i,1000) if(dp[n][3][i]) ans ++;
  cout << ans << endl;
}
