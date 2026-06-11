#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

int main(){
  ll h,w;
  cin >> h >> w;
  vector<string>s(h);
  for(int i=0; i<h; i++) cin >> s[i];
  vector<vector<ll>>dp(h,vector<ll>(w));
  
  if(s[0][0]=='#')dp[0][0]++;
  
  for(int i=1; i<h; i++){
    dp[i][0]=dp[i-1][0];
    if(s[i][0]=='#' && s[i-1][0]=='.')dp[i][0]++;
  }
    for(int i=1; i<w; i++){
    dp[0][i]=dp[0][i-1];
    if(s[0][i]=='#' && s[0][i-1]=='.')dp[0][i]++;
  }
  
  for(int i=1; i<h; i++){
    for(int j=1; j<w; j++){
      ll x=0,y=0;
      if(s[i][j]=='#' && s[i-1][j]=='.')x++;
      if(s[i][j]=='#' && s[i][j-1]=='.')y++;
      dp[i][j]=min(dp[i-1][j]+x,dp[i][j-1]+y);
    }
  }
  
  cout << dp[h-1][w-1] << endl;
  
}
       
        
      
  
    
