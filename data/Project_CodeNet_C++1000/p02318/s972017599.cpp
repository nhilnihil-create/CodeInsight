#include<iostream>
#include<string>
#include <algorithm>

using namespace std;

int main(){
  string X, Y;
  cin >> X;
  cin >> Y;
  int n = X.size();
  int m = Y.size();
  int dp[n+1][m+1];
  for(int i=0;i<n+1;i++){
    dp[i][0] = i;
  }
  for(int i=0;i<m+1;i++){
    dp[0][i] = i;
  }
  for(int i=1;i<n+1;i++){
    for(int j=1;j<m+1;j++){	
      if(X[i-1] == Y[j-1]){
	dp[i][j] = min(dp[i-1][j-1],min(dp[i][j-1]+1, dp[i-1][j]+1));
      }else{
	dp[i][j] = min(dp[i-1][j-1]+1,min(dp[i][j-1]+1,dp[i-1][j]+1));
	
      }
      //cout << dp[i][j];
    }
    //cout << endl;
  }
  cout << dp[n][m] << endl;
}
