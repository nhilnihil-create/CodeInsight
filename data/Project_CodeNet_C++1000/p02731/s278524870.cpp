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
  double edge;
  double area;
  
  lll l;

  cin >> l;

  edge = l/3.0d;

  area = edge * edge * edge;

  printf("%0.7lf\n",area);

  return 0;
}
