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
  int W,H,x,y;
  cin >> W >> H >> x >> y;
  double max = double(W)*double(H)/2;
  int judge = 0;
  if(x + x == W && y + y == H){
    judge = 1;
  }
  cout << fixed << setprecision(6) << max << " ";
  cout << judge << endl;
}
