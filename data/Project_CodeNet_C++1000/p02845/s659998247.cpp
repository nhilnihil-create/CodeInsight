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
int main(){
  int N;
  scanf("%d", &N);
  std::vector<int > A(N);
  for (int i=0; i<N; i++){
    scanf("%d", &A[i]);
  }
  int counter[3]={0, 0, 0};
  int add_index;
  long long ans = 1;
  long long mod = 1e9+7;
  for (int i=0; i<N; i++){
    if (counter[0]==A[i]) add_index=0;
    else if (counter[1]==A[i]) add_index=1;
    else if (counter[2]==A[i]) add_index=2;
    else {
      ans=0;
      break;
    }
    int same_count = 1;
    for (int j=0; j<3; j++){
      if (j==add_index) continue;
      if (counter[j]==A[i]) same_count++;
    }
    ans *= same_count;
    ans %= mod;
    counter[add_index]++;
  }
  std::cout << ans << std::endl;
  return 0;
}
