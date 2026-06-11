#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int h,w;
  int inf = 1e5+1;
  cin >> h >> w;
  
  vector<string>data(h);
  vector<vector<int>>dp(h,vector<int>(w));
  rep(i,0,h) cin >> data[i];
  if(data[0][0] != '#') dp[0][0] = 0;
  else dp[0][0] = 1;
  
  rep(i,0,h){
    rep(j,0,w){
      if(i == 0 && j == 0) continue;
      int l,u;
      if(j == 0) l = inf;
      else{
        l = dp[i][j-1];
        if(data[i][j] != data[i][j-1]) l++;
      }
      if(i == 0) u = inf;
      else{
        u = dp[i-1][j];
        if(data[i][j] != data[i-1][j]) u++;
      }
      dp[i][j] = min(l,u);
    }
  }
  if(data[h-1][w-1] == '#') dp[h-1][w-1]++;
  cout << dp[h-1][w-1]/2 << endl;
}