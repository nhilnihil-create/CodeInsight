#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> stu(N);
  for(int i = 0;i < N;i++){
    cin >> stu.at(i);
  }
  vector<int> ans(N);
  for(int i = 0;i < N;i++){
    ans.at(stu.at(i) - 1) = i + 1;
  }
  for(int i = 0;i < N;i++){
    cout << ans.at(i) << " ";
  }
  cout << endl;
  
  return 0;
}
