#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <deque>
#include <utility>

int main(){
  std::string S;
  std::cin >> S;
  int n = S.length();
  std::vector<int > L(n);
  for (int i=0; i<n; i++){
    L[i]=int(S[i])-int('0');
  }
  std::reverse(L.begin(), L.end());
  long long mod = 1e9+7;
  std::vector<std::vector<long long > > dp(n+4, std::vector<long long > (2));
  dp[0][0]=1;
  dp[0][1]=1;
  for (int i=0; i<n; i++){
    if (L[i]==1){
      dp[i+1][0] = dp[i][1] + (2*dp[i][0])%mod;
    } else {
      dp[i+1][0] = dp[i][0];
    }
    dp[i+1][1] = dp[i][1] * 3;
    dp[i+1][0] %= mod;
    dp[i+1][1] %= mod;
    //printf("%lld, %lld\n", dp[i+1][0], dp[i+1][1]);
  }
  long long ans = dp[n][0];
  std::cout << ans << std::endl;
  return 0;
}
 