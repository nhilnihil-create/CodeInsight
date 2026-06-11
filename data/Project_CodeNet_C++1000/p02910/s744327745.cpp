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
  string S;
  cin >> S;
  int x = 0;
  int judge = 0;
  x = S.size();
  for(int i = 0;i < x;i++){
    //cout << i << S.at(i) << endl;
    if((i + 1)% 2 == 0){
      if(S.at(i) == 'R'){
        judge = 1;
        break;
      }
    }else{
      if(S.at(i) == 'L'){
        judge = 1;
        break;
      }
    }
  }

  if(judge == 1){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
  }
}
