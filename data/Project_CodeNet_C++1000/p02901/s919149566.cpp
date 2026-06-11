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

int dp[10000];
int main(){
  int N, M;
  scanf("%d", &N);
  scanf("%d", &M);
  std::vector<int > a(M), b(M);
  std::vector<int > c[1004];
  int cc;
  for (int i=0 ;i<M; i++){
    scanf("%d", &a[i]);
    scanf("%d", &b[i]);
    for (int j=0 ;j<b[i]; j++){
      scanf("%d", &cc);
      cc--;
      c[i].push_back(cc);
    }
  }

  for (int i=0; i<10000; i++){
    dp[i]=1000000005;
  }
  
  dp[0]=0;
  
  for (int i=0; i<5000; i++){
  //for (int i=0; i<30; i++){
    //printf("====i=%d====\n", i);
    for (int j=0; j<M; j++){
      int s=i;
      for (int k=0; k<b[j]; k++){
	s = s|(1<<c[j][k]);
      }
      dp[s]=std::min(dp[i]+a[j], dp[s]);
      //printf("dp[%d]=%d\n", s, dp[s]);
    }
  }
  printf("%d\n", (dp[(1<<N)-1]==1000000005)?-1:dp[(1<<N)-1]);
  return 0;
}
