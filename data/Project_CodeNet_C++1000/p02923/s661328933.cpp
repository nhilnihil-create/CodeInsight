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
  long long N = 0;
  cin >> N;
  vector<long long> high(N);
  vector<int> rank(N);
  for(int i = 0;i < N;i++){
    cin >> high.at(i);
    rank.at(i) = 0;
  }
  long long now = 0;
  now = high.at(0);
  int count = 0;
  for(int i = 1;i < N;i++){
    if(now >= high.at(i)){
      count++;
    }else{
      count = 0;
    }
    now = high.at(i);
    rank.at(i) = count;
  }
  int ans = 0;
  for(int i = 0;i < N;i++){
    ans = max(ans,rank.at(i));
  }
  cout << ans << endl;
}
