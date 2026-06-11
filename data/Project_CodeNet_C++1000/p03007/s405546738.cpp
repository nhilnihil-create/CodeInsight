#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unordered_map>
#include <vector>

int main() {
  int N;
  scanf("%d", &N);
  std::vector<int > A(N);
  std::vector<bool > positive(N);
  for (int i=0; i<N; i++){
    scanf("%d", &A[i]);
  }
  std::sort(A.begin(), A.end());
  int positive_count = 1;
  int negative_count = 1;
  positive[0]=false;
  positive[N-1]=true;
  for (int i=1; i<N-1; i++){
    if (A[i]>=0) {
      positive[i]=true;
      positive_count++;
    } else {
      positive[i]=false;
      negative_count++;
    }
  }
  long long ans = 0;
  for (int i=0; i<N; i++){
    if (positive[i]){
      ans += A[i];
    } else {
      ans -= A[i];
    }
  }
  printf("%lld\n", ans);
  long long left = A[0];
  for (int i=0; i<positive_count-1; i++){
    printf("%lld %d\n", left, A[i+negative_count]);
    left -= A[i+negative_count];
  }
  printf("%d %lld\n", A[N-1],left);
  left = A[N-1]-left;
  for (int i=0; i<negative_count-1; i++){
    printf("%lld %d\n", left, A[1+i]);
    left -= A[i+1];
  }
  return 0;
}
