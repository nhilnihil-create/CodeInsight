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
  int N = 0;
  cin >> N;
  vector<int> len(N);
  for(int i = 0;i < N;i++){
    cin >> len.at(i);
  }
  int judge = 1;
  int now = len.at(N - 1);
  for(int i = N - 2;i >= 0;i--){
    if(len.at(i) <= now){
      now = len.at(i);
    }else{
      if(len.at(i) - 1 <= now){
        len.at(i) -= 1;
        now = len.at(i);
      }else{
        judge = 0;
        break;
      }
    }
  }
  if(judge){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}
