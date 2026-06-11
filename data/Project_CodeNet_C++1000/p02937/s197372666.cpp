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
  std::string s, t;
  std::cin >> s;
  std::cin >> t;
  std::vector<int > index_vec[26];
  for (int i=0; i<s.length(); i++){
    int value = int(s[i])-int('a');
    index_vec[value].push_back(i);
    //printf("push index_vec[%d] to %d\n", value, i);
  }
  long long ans = 0;
  int current_position = -1;
  for (int i=0; i<t.length(); i++){
    int value = int(t[i])-int('a');    
    if (index_vec[value].size()==0){
      printf("-1\n");
      return 0;
    }
    auto itr = std::upper_bound(index_vec[value].begin(), index_vec[value].end(), current_position);
    if (itr==index_vec[value].end()){
      ans += index_vec[value][0]+int(s.length())-current_position;
      current_position = index_vec[value][0];
    } else {
      //int index = itr-index_vec[value].begin();
      //ans +=  index_vec[value][index]-current_position;
      //current_position = index_vec[value][index];
      ans += *itr - current_position;
      current_position = *itr;
    }
    /*bool exist_current_set = false;
    for (int j=0; j<index_vec[value].size(); j++){
      if (current_position<index_vec[value][j]){
        exist_current_set = true;
        ans += index_vec[value][j]-current_position;
        //printf("ans+=%d-%d=%d\n", index_vec[value][j], current_position, index_vec[value][j]-current_position);
        current_position = index_vec[value][j];
        break;
      }
    }
    if (!exist_current_set){
      ans += index_vec[value][0]+int(s.length())-current_position;
      current_position = index_vec[value][0];
      }*/
  }
  std::cout << ans << std::endl;
  return 0;
}
