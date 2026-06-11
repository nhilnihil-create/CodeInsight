#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;

int main() {
  int H,W;
  cin>>H>>W;
  vector<string> s(H);
  vector<vector<int>> dp(H,vector<int>(W,100000));
  int dx[]={1,0};
  int dy[]={0,1};
  
  for(int i=0;i<H;i++){
    cin>>s[i];
  }

  if(s[0][0]=='.'){dp[0][0]=0;}
  else{dp[0][0]=1;}
  
  for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
         for(int d=0;d<2;d++){
            int ni=i+dy[d],nj=j+dx[d];
            if(ni>=H||nj>=W){continue;}
            int add=0;
            if(s[i][j]=='.'&&s[ni][nj]=='#'){add=1;}
            chmin(dp[ni][nj],dp[i][j]+add);
         } 
      }
  }

  cout<<dp[H-1][W-1]<<endl;
  return 0;
}