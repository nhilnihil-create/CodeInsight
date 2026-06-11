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
#include <set>
#include <deque>

int main(){
  int N;
  scanf("%d", &N);
  std::vector<int> x(N), y(N);
  for (int i=0; i<N; i++){
    scanf("%d", &x[i]);
    scanf("%d", &y[i]);
  }
  //std::pair table[54][54];
  std::map<std::pair<int, int>, int> mp;
  for (int i=0; i<N; i++){
    for (int j=0; j<N; j++){
      if (i==j) continue;
      //table[i][j] = std::make_pair(x[i]-x[j], y[i]-y[j]);
      mp[std::make_pair(x[i]-x[j], y[i]-y[j])]++;
    }
  }
  int max = 0;
  for (auto &entry : mp){
    max = std::max(max, entry.second);
  }
  std::cout << N-max << std::endl;
  return 0;
}
