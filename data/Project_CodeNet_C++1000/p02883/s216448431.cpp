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
  int N;
  long long K;
  scanf("%d", &N);
  scanf("%lld", &K);
  std::vector<int > A(N), F(N);
  for (int i=0; i<N; i++){
    scanf("%d", &A[i]);
  }
  for (int i=0; i<N; i++){
    scanf("%d", &F[i]);
  }
  std::sort(A.begin(), A.end(), std::greater<int>());
  std::sort(F.begin(), F.end());
  long long min = -1;
  long long max = 1e18;
  while(max-min>1) {
    //printf("[%lld, %lld]\n", min, max);
    long long mid = (min+max)/2;
    bool ok = [&]{
      long long sum = 0;
      for (int i=0; i<N; i++){
	if ((long long)A[i]*F[i]>mid){
	  sum += A[i]-mid/(long long)F[i];
	}
      }
      return sum<=K;
    }();
    if (ok) {
      max=mid;
    } else {
      min=mid;
    }
  }
  std::cout << max << std::endl;
  return 0;
}
