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
  vector<int> P(N);
  for(int i = 0;i < N;i++){
    cin >> P.at(i);
  }
  int count = 0,a = 0,b = 0,c = 0;
  for(int i = 1;i < N - 1;i++){
    a = P.at(i - 1);
    b = P.at(i);
    c = P.at(i + 1);
    if(a < b && b < c){
      count++;
    }else if(a > b && b > c){
      count++;
    }
  }
  cout << count << endl;
}
