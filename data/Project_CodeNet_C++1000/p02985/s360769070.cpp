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
  std::vector<int > edge[100004];
  int a, b;
  for (int i=0; i<N-1; i++){
    scanf("%d", &a);
    scanf("%d", &b);
    a--;
    b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  int start;
  for (int i=0; i<N; i++){
    if (edge[i].size()==1){
      start=i;
      break;
    }
  }

  long long ans = K;
  long long mod = 1e9+7;
  std::queue<int > queue;
  std::vector<bool > used(N+4, false);
  queue.push(start);
  used[start]=true;
  bool initial = true;
  while(queue.size()>0){
    int v = queue.front();
    queue.pop();
    int childnum = (initial)?(edge[v].size()):(edge[v].size()-1);
    int multiple = (initial)?(K-1):(K-2);
    for (int i=0; i<childnum; i++){
      ans *= multiple;
      ans %= mod;
      multiple--;
    }
    initial=false;
    for (int vv : edge[v]){
      if (!used[vv]){
	queue.push(vv);
	used[vv] = true;
      }
    }
  };
  std::cout << ans << std::endl;
  return 0;
}
 