#include<bits/stdc++.h>
using namespace std;
int main(){
int H,W;
  cin>>H>>W;
  vector<vector<char>>A(H,vector<char>(W));
  for(int i=0;i<H;i++){
  string s;
    cin>>s;
    for(int j=0;j<W;j++)
       A[i][j]=s.at(j);
  }vector<vector<int>>dp(H,vector<int>(W));
  if(A[0][0]=='.')
    dp[0][0]=0;
  else
    dp[0][0]=1;
  for(int i=1;i<H;i++){
  if(A[i][0]=='.')
    dp[i][0]=dp[i-1][0];
    else{
    if(A[i-1][0]=='#')
      dp[i][0]=dp[i-1][0];
      else
        dp[i][0]=dp[i-1][0]+1;
    }
  }for(int j=1;j<W;j++){
  if(A[0][j]=='.')
    dp[0][j]=dp[0][j-1];
    else{
    if(A[0][j-1]=='#')
      dp[0][j]=dp[0][j-1];
      else
        dp[0][j]=dp[0][j-1]+1;
    }
  }for(int i=1;i<H;i++){
   for(int j=1;j<W;j++){
   if(A[i][j]=='.')
     dp[i][j]=min(dp[i-1][j],dp[i][j-1]);
     else{
     int a=dp[i-1][j]; int b=dp[i][j-1];
       if(A[i-1][j]=='.')
         a++;
       if(A[i][j-1]=='.')
         b++;
     dp[i][j]=min(a,b);
     
     }
     
   }
  }int ans=dp[H-1][W-1];
  cout<<ans<<endl;
   return 0;
}