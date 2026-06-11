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

int dp[5004][5004];

int main(){
  int N;
  scanf("%d", &N);
  std::string s;
  std::cin >> s;
  int ans = 0;
  dp[N][N]=0;
  for (int i=N-1; i>=0; i--){
    for (int j=N-1; j>=0; j--){
      if (s[i]==s[j]) {
	dp[i][j] = dp[i+1][j+1]+1;
	ans = std::max(ans, std::min(dp[i][j], j-i));
      }
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
 