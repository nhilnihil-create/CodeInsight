#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <cmath>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int mod=1e9+7;
const int INF=1001001001;
int main() {
 int H,W;
 cin>>H>>W;
 vector<string>s(H);
 for(int i=0;i<H;i++){
   cin>>s[i];
 }
 vector<vector<int>>dp(H,vector<int>(W,INF));
 if(s[0][0]=='#'){dp[0][0]=1;}
 else{dp[0][0]=0;}

 vector<int>dx={0,1};
 vector<int>dy={1,0};

 for(int i=0;i<H;i++){
   for(int j=0;j<W;j++){
     for(int k=0;k<2;k++){
       int nextx=j+dx[k],nexty=i+dy[k];
       if(nextx>=W||nexty>=H){continue;}
       if(s[nexty][nextx]=='#'&&s[i][j]=='.'){chmin(dp[nexty][nextx],dp[i][j]+1);}
       else{chmin(dp[nexty][nextx],dp[i][j]);}
     }
   }
 }
 cout<<dp[H-1][W-1]<<endl;
 return 0;  
}