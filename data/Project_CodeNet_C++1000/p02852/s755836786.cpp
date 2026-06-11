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
  int N, M;
  scanf("%d", &N);
  scanf("%d", &M);
  std::string s;
  std::cin >> s;
  int pos = N;
  bool ng = false;
  std::vector<int> ans;
  while(pos>0 && !ng){
    int next=std::max(0, pos-M);
    while(next<pos){
      if (s[next]=='0') break;
      next++;
    }
    if (next==pos) {
      ng=true;
      break;
    }
    ans.push_back(pos-next);
    pos=next;
  }
  //printf("ans.size()=%d\n", ans.size());
  std::reverse(ans.begin(), ans.end());
  if (ng){
    printf("-1\n");
  } else {
    for (int p : ans){
      printf("%d\n", p);
    }
  }
  return 0;
  
}
 