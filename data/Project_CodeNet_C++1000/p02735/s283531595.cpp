#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

const int INF=1e9;
int h,w,stat;
string str;
int main(){
  cin >>h>>w;
  vector<vector<bool>> s(h,vector<bool>(w));
  rep(r,h){
    cin>>str;
    rep(c,w){
      if(str[c]=='#') s[r][c]=false;//black
      else s[r][c]=true;//white
      
     // cout<<s[r][c]<<" ";
    }
    //cout<<endl;
  }
  vector<vector<int>> dp(h,vector<int>(w));// dp[i].. i回移動時に最小となる反転回数．
  rep(i,h)rep(j,w) dp[i][j]=INF;
  
  if(s[0][0]) dp[0][0]=0;
  else dp[0][0]=1;
  
  
  for(int i=1; i<=h+w-1;i++){//i回移動する． [i][0],[i-1][1],...[0][i]
    int j_st=max(i-w+1,0);
    int j_end=min(h-1,i);
    for(int j=j_st; j<=j_end;j++){// j回は下に移動する場合． dp[j]
      int k=i-j;
      if(j>=1){
      	if(s[j][k]^s[j-1][k]){ 
          dp[j][k]=min(dp[j][k],dp[j-1][k]+1);
        }else{
          dp[j][k]=min(dp[j][k],dp[j-1][k]);
        }
      }
       
      if(k>=1){
      	if(s[j][k]^s[j][k-1]){
          dp[j][k]=min(dp[j][k],dp[j][k-1]+1);
      	}else{
          dp[j][k]=min(dp[j][k],dp[j][k-1]);
      	}      
      }
      
      
    }
    
  }
  /*
  rep(i,h){
    rep(j,w){
      cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }
  */
  
  int ans=(dp[h-1][w-1]+1)/2;
  //if(s[0][0]==false) ans+=1;
  
  
  cout<<ans<<endl;
}
