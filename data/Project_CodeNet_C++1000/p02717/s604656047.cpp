#include <algorithm>
#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<set>
#include<string>
#include <sstream>
#include<bitset>

#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
const int INF = 0x7fffffff;
using lll = long long;
using ull = unsigned long long;
using namespace std;


int main(){
  lll ii,jj,kk;
  vector<int> ret;
  int x,y,z,tmp;

  cin >> x >> y >> z;

  tmp = x;
  x = y;
  y = tmp;
  tmp = x;
  x = z;
  z = tmp;

  cout << x << " " << y << " "  << z << endl;
  

  return 0;
}
