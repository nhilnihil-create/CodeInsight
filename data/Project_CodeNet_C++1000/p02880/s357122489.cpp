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
  int judge = 0;
  for(int i = 1;i <= 9;i++){
    for(int j = 1;j <= 9;j++){
      if(N == i*j){
        judge = 1;
        break;
      }
    }
  }
  if(judge == 1){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
