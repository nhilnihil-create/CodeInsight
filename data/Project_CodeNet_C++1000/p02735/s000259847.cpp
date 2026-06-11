#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){

  int h,w;
  cin >> h >> w;
  vector<string> v(h);
  rep(i,h)cin >> v[i];
  vector<vector<int>> dp(h,vector<int>(w,1 << 30));
  dp[0][0] = 0;
  rep(i,w-1)if(v[0][i+1] == '#' && v[0][i] == '.'){
    dp[0][i+1] = dp[0][i]+1;
  }else{
    dp[0][i+1] = dp[0][i];
  }
  for(int i = 1;i < h;i++)rep(j,w){
    if(v[i-1][j] == '.' && v[i][j] == '#')dp[i][j] = min(dp[i][j],dp[i-1][j] + 1);
    else dp[i][j] = min(dp[i][j],dp[i-1][j]);
    if(j-1 >= 0 && v[i][j-1] == '.' && v[i][j] == '#')dp[i][j] = min(dp[i][j],dp[i][j-1]+1);
    else if(j-1 >= 0)dp[i][j] = min(dp[i][j],dp[i][j-1]);
  }
  cout << dp[h-1][w-1] + (v[0][0] == '#') << endl;





  return 0;
}