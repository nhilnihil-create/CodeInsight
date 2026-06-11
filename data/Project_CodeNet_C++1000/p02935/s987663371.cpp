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
  vector<int> value(N);
  for(int i = 0;i < N;i++){
    cin >> value.at(i);
  }
  sort(value.begin(),value.end());
  double ans = 0.0;
  ans = (value.at(0) + value.at(1)) / 2.0;
  //cout << fixed << setprecision(16) << ans << endl;
  for(int i = 2;i < N;i++){
    ans = (ans + value.at(i)) / 2.0;
  }
  cout << fixed << setprecision(16) << ans << endl;
}
