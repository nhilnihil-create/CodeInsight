#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

long long int MOD = 1e9+7;

int main(){
  
  long long int N, M, tmp;
  scanf("%lld%lld", &N, &M);
  std::vector<long long int> S, T;
  for(long long int i = 0; i < N; i++){
    scanf("%lld", &tmp);
    S.push_back(tmp);
  }
  for(long long int i = 0; i < M; i++){
    scanf("%lld", &tmp);
    T.push_back(tmp);
  }
  
  /*std::cerr << "S:" << std::endl;
  for(long long int i = 0; i < N; i++){
    std::cerr << S[i] << " ";
  }std::cerr << std::endl;
  
  std::cerr << "T:" << std::endl;
  for(long long int i = 0; i < M; i++){
    std::cerr << T[i] << " ";
  }std::cerr << std::endl;*/
  
  // solve problem
  std::vector<std::vector<long long int> > dp(N+1);
  for(long long int i = 0; i <= N; i++){
    for(long long int j = 0; j <= M; j++){
      dp[i].push_back(0);
    }
  }
  dp[0][0] = 1;
  for(long long int i = 1; i <= N; i++)dp[i][0] = 1;
  for(long long int j = 1; j <= M; j++)dp[0][j] = 1;
  
  for(long long int i = 1; i <= N; i++){
    for(long long int j = 1; j <= M; j++){
      if(S[i-1] == T[j-1]){
        //std::cerr << "S[i-1] == T[i-1]" << std::endl;
        dp[i][j] = dp[i-1][j] + dp[i][j-1];
      }
      else{
        //std::cerr << "else" << std::endl;
        dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
      }
      dp[i][j] = (dp[i][j] + MOD)%MOD;
    }
  }
  
  /*std::cerr << "dp:" << std::endl;
  for(long long int i = 0; i <=N; i++){
    for(long long int j = 0; j <= M; j++){
      std::cerr << dp[i][j] << " ";
    }std::cerr << std::endl;
  }*/
  
  std::cerr << "Answer:" << std::endl;
  std::cout << dp[N][M] << std::endl;
  
  return 0;
  
}
