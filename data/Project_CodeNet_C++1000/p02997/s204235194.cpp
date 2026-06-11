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
  int N, K;
  scanf("%d", &N);
  scanf("%d", &K);
  if (K>(N-1)*(N-2)/2){
    printf("-1\n");
    return 0;
  }
  std::vector<std::pair<int, int > > ans;
  int diff = (N-1)*(N-2)/2-K;
  for (int i=2; i<=N; i++){
    ans.push_back(std::make_pair(1, i));
  }
  bool end=false;
  for (int i=2; i<N; i++){
    if (end) break;
    for (int j=i+1; j<=N; j++){
      if (diff==0){
	end=true;
	break;
      }
      ans.push_back(std::make_pair(i, j));
      diff--;
    }
  }
  printf("%d\n", ans.size());
  for (int i=0; i<ans.size(); i++){
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}
