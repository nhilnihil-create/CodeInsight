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
  string S;
  cin >> N;
  cin >> S;
  string s1,s2;
  if(N % 2 == 1){
    cout << "No" << endl;
  }else{
    int x = N/2;
    for(int i = 0;i < x;i++){
      s1 += S.at(i);
    }
    for(int i = x;i < N;i++){
      s2 += S.at(i);
    }
    int judge = 1;
    for(int i = 0;i < x;i++){
      if(s1.at(i) != s2.at(i)){
        judge = 0;
        break;
      }
    }
    if(judge == 0){
      cout << "No" << endl;
    }else{
      cout << "Yes" << endl;
    }
  }
}
