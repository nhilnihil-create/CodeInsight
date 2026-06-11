#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
 
int Levenstein(std::string a,std::string b){
  int dp[a.size()+1][b.size()+1];
 
  for(int i=0;i<=a.size();i++){
  	dp[i][0]=i;
  }
  for(int i=0;i<=b.size();i++){
  	dp[0][i]=i;
  }
 
  for(int i=1;i<=a.size();i++){
    for(int j=1;j<=b.size();j++){
      int cost=(a[i-1]==b[j-1])?0:1;
      dp[i][j]=std::min(dp[i-1][j]+1,std::min(dp[i][j-1]+1,dp[i-1][j-1]+cost));
    }
  }
  return dp[a.size()][b.size()];
}
 
int main(void){
 
  std::string a,b;
  std::cin >> a >> b;
  std::cout << Levenstein(a,b) << std::endl;
 
  return 0;
}

