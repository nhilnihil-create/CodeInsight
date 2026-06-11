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
  int N,L;
  cin >> N >> L;
  vector<int> taste(N);
  /*for(int i = 0;i < N;i++){
    taste.at(i) = 0;
  }*/
  for(int i = 1;i <= N;i++){
    taste.at(i - 1) = L + i - 1;
  }
  int count = 10000,countx = 10000,X = 10000;
  for(int i = 0;i < N;i++){
    count = min(count,abs(taste.at(i)));
    if(count != countx){
      X = i;
    }
    countx = count;
  }
  int ans = 0;
  for(int i = 0;i < N;i++){
    if(i != X){
      ans += taste.at(i);
    }
  }
  cout << ans << endl;
}
