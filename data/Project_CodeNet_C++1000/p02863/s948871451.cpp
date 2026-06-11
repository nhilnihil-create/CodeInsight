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

int dp[3004][3004];

int main(){
  int N, T;
  scanf("%d", &N);
  scanf("%d", &T);
  std::vector<int > A(N), B(N);
  int max=-1;
  int maxindex=-1;
  std::vector<std::pair<int, int > > pr(N);
  for (int i=0; i<N; i++){
    //scanf("%d", &A[i]);
    //scanf("%d", &B[i]);
    scanf("%d", &pr[i].first);
    scanf("%d", &pr[i].second);
  }
  std::sort(pr.begin(), pr.end());
  for (int i=0; i<N; i++){
    A[i]=pr[i].first;
    B[i]=pr[i].second;
    //printf("(%d, %d)\n", A[i], B[i]);
  }
  for (int i=0; i<3004; i++){
    for (int j=0; j<3004; j++){
      dp[i][j]=-1;
    }
  }
  dp[0][0]=0;
  for (int i=0; i<N; i++){
    /*    if (i==maxindex) {
      for (int j=0; j<=T; j++){
	dp[i+1][j]=dp[i][j];
	//printf("maxindex dp[%d][%d]=%d\n", i+1, j, dp[i+1][j]);
	}*/
    //} else {
    for (int j=0; j<T; j++){
      dp[i+1][j]=std::max(dp[i+1][j], dp[i][j]);
      if (dp[i][j]!=-1 && j+A[i]<T){
	dp[i+1][j+A[i]]=std::max(dp[i+1][j+A[i]], dp[i][j]+B[i]);
	//printf("dp[%d][%d]=%d\n", i+1, j+A[i], dp[i+1][j+A[i]]);
      } else if (dp[i][j]!=-1 && j+A[i]>=T){
	dp[i+1][T]=std::max(dp[i+1][T], dp[i][j]+B[i]);
	//printf("dp[%d][%d]=%d\n", i+1, T, dp[i+1][T]);
      }
    }
    dp[i+1][T]=std::max(dp[i+1][T], dp[i][T]);
  }
  int dpmax=-1;
  for (int j=0; j<=T; j++){
    dpmax = std::max(dpmax, dp[N][j]);
  }
  //printf("dpmax=%d, max=%d\n", dpmax, max);
  //std::cout << dpmax+max << std::endl;
  std::cout << dpmax << std::endl;
  return 0;
}
 