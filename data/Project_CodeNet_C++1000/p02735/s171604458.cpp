#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define endl "\n"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int H,W;
  cin>>H>>W;
  vector<string>s(H);
  for(int i=0;i<H;i++)cin>>s[i];
  vector<vector<int>>dp(H,vector<int>(W,INT_MAX));
  if(s[0][0]=='#')dp[0][0]=1;
  else dp[0][0]=0;
  int dx[2]={0,-1};
  int dy[2]={-1,0};
  for(int y=0;y<H;y++){
    for(int x=0;x<W;x++){
      if(x==0&&y==0)continue;
      for(int k=0;k<2;k++){
        int nx=x+dx[k];
        int ny=y+dy[k];
        if(0<=nx&&nx<W&&0<=ny&&ny<H){
          if(s[y][x]=='.')dp[y][x]=min(dp[ny][nx],dp[y][x]);
          else if(s[y][x]=='#'&&s[ny][nx]=='#')dp[y][x]=min(dp[ny][nx],dp[y][x]);
          else if(s[y][x]=='#'&&s[ny][nx]=='.')dp[y][x]=min(dp[ny][nx]+1,dp[y][x]);
        }
      }
    }
  }


  cout<<dp[H-1][W-1]<<endl;
  return 0;
}
