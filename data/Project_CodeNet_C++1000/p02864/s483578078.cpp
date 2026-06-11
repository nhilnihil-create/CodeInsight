#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <cstring>
#include <algorithm>


const long long int infty = 1e14;
long long int zero = 0;

int main(){
  
  // read problem
  long long int N, K, tmp;
  std::vector<long long int> H;
  scanf("%lld%lld", &N, &K);
  for(long long int i = 0; i < N; i++){
    scanf("%lld", &tmp);
    H.push_back(tmp);
  }
  
  // solve problem
  std::vector<std::vector<long long int> > dp(N);
  for(long long int i = 0; i < N; i++){
    for(long long int j = 0; j <= K; j++){
      dp[i].push_back(0);
    }
  }
  
  // calculate dp
  for(long long int i = 0; i < N; i++){
    
    // dp[i][j] for j<i
    for(long long int j = 0; j < i && j<=K; j++){
      // initialize
      if(j>0){
        dp[i][j] = dp[i][j-1];
      }
      else{
        dp[i][j] = infty;
      }
      // upadte
      for(long long int d = 0; j-d>=0; d++){
        dp[i][j] = std::min(dp[i][j], dp[i-1-d][j-d] + std::max(zero, H[i]-H[i-1-d]));
      }
    }
    // dp[i][i]
    if(i==0){
      dp[0][0] = H[0];
    }
    if(i>0 && i<=K){
      dp[i][i] = std::min(H[i], dp[i][i-1]);
    }
  }
  
  /*std::cerr << "result of dp:" << std::endl;
  for(long long int i = 0; i < N; i++){
    for(long long int j = 0; j <= K; j++){
      std::cerr << dp[i][j] << " ";
    }std::cerr << std::endl;
  }*/
  
  
  // calculate answer
  if(N==K){
    std::cerr << "Answer:" << std::endl;
    std::cout << 0 << std::endl;
    return 0;
  }
  
  long long int ans = infty;
  for(long long int i = 0; i < N; i++){
    if(K >= N-i-1){
      ans = std::min(ans, dp[i][K-(N-i-1)]);
    }
  }
  std::cerr << "Answer:" << std::endl;
  std::cout << ans << std::endl;
  
  return 0;
}
