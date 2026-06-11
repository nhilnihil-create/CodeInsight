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
  int X,D;
  cin >> X >> D;
  int box[X][D];
  for(int i = 0;i < X;i++){
    for(int j = 0;j < D;j++){
      cin >> box[i][j];
    }
  }
  //cout << "N" << endl;
  long long len = 0;
  int ans = 0;
  for(int i = 0;i < X;i++){
    for(int j = i + 1;j < X;j++){
      len = 0;
      for(int l = 0;l < D;l++){
        int diff = abs(box[i][l] - box[j][l]);
        len += diff * diff;
      }
      for(int l = 0;l <= len;l++){
        if(l*l == len){
          ans++;
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}
