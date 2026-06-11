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
  vector<long long> mon(N+1,0);
  vector<long long> hero(N,0);
  for(int i = 0;i < N + 1;i++){
    cin >> mon.at(i);
  }
  for(int i = 0;i < N;i++){
    cin >> hero.at(i);
  }
  long long count = 0,x = 0,y = 0;
  for(int i = 0;i < N;i++){
    x = min(mon.at(i),hero.at(i));
    count += x;
    hero.at(i) -= x;
    if(hero.at(i) != 0){
      y = min(mon.at(i + 1),hero.at(i));
      count += y;
      mon.at(i + 1) -=y;
    }
  }
  cout << count << endl;
}
