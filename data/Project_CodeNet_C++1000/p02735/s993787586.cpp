#include <bits/stdc++.h>
using namespace std;
 

int main() {
  int h,w;
  cin >> h>> w;
  string s[h][w];
  int dp[h][w];
  string tmp;
  for(int i = 0; i < h;i++){
    cin >> tmp;
    for(int j = 0; j < w;j++){
        s[i][j] = tmp[j];
    }
  }
  int tmpx,tmpy;
  
  if(s[0][0] == "#"){
    dp[0][0] = 1;
    
  }else{
    dp[0][0] = 0;
  }
  
  for(int i = 0; i < h;i++){
    for(int j = 0; j < w;j++){
      if(i == 0 && j == 0){
      
      }else if(i == 0){
        if(s[i][j-1] != s[i][j] && s[i][j] == "#" ){
          
          dp[i][j] = dp[i][j-1] + 1;
        }else {
          dp[i][j] = dp[i][j-1];
        }
      }else if(j == 0){ 
        if(s[i-1][j] != s[i][j] && s[i][j] == "#" ){
          dp[i][j] = dp[i-1][j] + 1;
        }else {
          dp[i][j] = dp[i-1][j];
        }
      }else{
        if(s[i][j-1] != s[i][j] && s[i][j] == "#" ){
          tmpy = dp[i][j-1] + 1;
        }else {
          tmpy = dp[i][j-1];
        }
    
        if(s[i-1][j] != s[i][j] && s[i][j] == "#" ){
          tmpx = dp[i-1][j] + 1;
        }else {
          tmpx = dp[i-1][j];
        }
        
        dp[i][j] = min(tmpx,tmpy);
      }
    }
  }
  cout << dp[h-1][w-1] << endl;
  
  //for(int i = 0; i < h;i++){
  //  for(int j = 0; j < w;j++){
  //    cout << dp[i][j] << " ";
  //  }
  //  cout << endl;
  //}
  
 }