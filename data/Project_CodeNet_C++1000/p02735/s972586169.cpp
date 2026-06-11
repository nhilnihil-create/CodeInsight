#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<lli> vlli;
typedef vector<bool> vb;
long long int max(long long int a,long long int b){
  if(a>b)
    return a;
  else
    return b;
}
long long int min(long long int a,long long int b){
  if(a<b)
    return a;
  else
    return b;
}
long long int binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a % m;
      a = a * a % m;
      b >>= 1;
    }
  return res;
}
long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}
 
//############################ENDOFTEMPLATE############################

void solve(){
  int n,m;
  cin>>n>>m;
  vector<string> grid(n);

  for(int i = 0;i<n;i++){
    cin>>grid[i];
  }

  vector<vector<int>> dp(n,vector<int>(m));

  if(grid[0][0]=='#')
    dp[0][0] = 1;

  for(int i = 1;i<n;i++){
    if(grid[i][0]=='#'){
      if(grid[i-1][0]=='#')
        dp[i][0] = dp[i-1][0];
      else
        dp[i][0] = dp[i-1][0]+1;
    }

    else{
      dp[i][0] = dp[i-1][0];
    }
  }


  for(int i = 1;i<m;i++){
    if(grid[0][i]=='#'){
      if(grid[0][i-1]=='#')
        dp[0][i] = dp[0][i-1];
      else
        dp[0][i] = dp[0][i-1]+1;
    }
    else{
      dp[0][i] = dp[0][i-1];
    }
  }

  for(int i = 1;i<n;i++){
    for(int j = 1;j<m;j++){
      if(grid[i][j]=='#'){
        dp[i][j] = min(grid[i-1][j]=='#'?dp[i-1][j]:dp[i-1][j]+1,grid[i][j-1]=='#'?dp[i][j-1]:dp[i][j-1]+1);
      }
      else{
        dp[i][j] = min(dp[i-1][j],dp[i][j-1]);
      }
    }
  }


  cout<<dp[n-1][m-1];
}
 
 
 
 
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  //freopen("moobuzz.in","r",stdin);
  //freopen("moobuzz.out","w",stdout);
  int t = 1;
  //cin>>t;
  while(t--){
    solve();
  }
}