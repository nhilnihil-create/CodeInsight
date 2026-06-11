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

bool same[5004][5004];

int main(){
  int N;
  scanf("%d", &N);
  std::string s;
  std::cin >> s;
  for (int i=1; i<N; i++){
    for (int j=0; j<N; j++){
      if (j+i>=N) same[i][j]=false;
      else same[i][j]=(s[j+i]==s[j]);
    };
  }
  int ans = 0;
  for (int i=1; i<N; i++){
    int count_max = 0;
    int count = 0;
    for (int j=0; j<N; j++){
      if (same[i][j]) {
	count++;
	count_max=std::max(count, count_max);
      }
      else count=0;
    }
    count_max = std::min(count_max, i);
    ans = std::max(ans, count_max);
  }
  std::cout << ans << std::endl;
  return 0;
}
 