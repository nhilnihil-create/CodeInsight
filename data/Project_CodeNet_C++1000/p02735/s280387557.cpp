#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  int n, m;
  cin >> n >> m;
  char a[n][m];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> a[i][j];
    }
  }
  int dp[n][m];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      dp[i][j] = 1000000000;
    }
  }
  if(a[0][0] == '.'){
    dp[0][0] = 0;
  }else{
    dp[0][0] = 1;
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(!i && !j){
        continue;
      }
      if(!i){
        if(a[i][j] == '.'){
          dp[i][j] = dp[i][j-1];
        }else{
          if(a[i][j-1] == '#'){
            dp[i][j] = dp[i][j-1];
          }else{
            dp[i][j] = dp[i][j-1]+1;
          }
        }
      }else if(!j){
        if(a[i][j] == '.'){
          dp[i][j] = dp[i-1][j];
        }else{
          if(a[i-1][j] == '#'){
            dp[i][j] = dp[i-1][j];
          }else{
            dp[i][j] = dp[i-1][j]+1;
          }
        }
      }else{
        if(a[i][j] == '.'){
          dp[i][j] = min(dp[i][j-1], dp[i-1][j]);
        }else{
          if(a[i][j] == a[i-1][j]){
            dp[i][j] = min(dp[i][j], dp[i-1][j]);
          }else{
            dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
          }
          if(a[i][j] == a[i][j-1]){
            dp[i][j] = min(dp[i][j], dp[i][j-1]);
          }else{
            dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
          }
        }
      }
    }
  }
  cout << dp[n-1][m-1];
}