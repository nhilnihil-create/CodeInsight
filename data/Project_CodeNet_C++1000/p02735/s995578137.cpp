#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>


char grid[110][110];
int dp[110][110];
const int INF=INT_MAX;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
  int h,w;
  cin>>h>>w;
  rep(i,h)rep(j,w){
    cin>>grid[i][j];
    dp[i][j]=INF;
  }
  if(grid[0][0]=='#') dp[0][0]=1;
  else dp[0][0]=0;
  rep(i,h)rep(j,w){
    if(i==0&&j==0) continue;
    if(i==0){
      dp[i][j]=dp[i][j-1];
      if(grid[i][j]!=grid[i][j-1]) dp[i][j]++;
    }
    else if(j==0){
      dp[i][j]=dp[i-1][j];
      if(grid[i][j]!=grid[i-1][j]) dp[i][j]++;
    }else{
      int x = dp[i-1][j] + (grid[i][j]!=grid[i-1][j]);
      int y = dp[i][j-1] + (grid[i][j]!=grid[i][j-1]);
      dp[i][j]=min(x,y);
    }
  }
  if(grid[h-1][w-1]=='#') dp[h-1][w-1]++;
  cout<<(dp[h-1][w-1])/2<<endl;
}