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

  string alpha;
  char   res;
  cin >> alpha;

  if('a' <= alpha[0] && alpha[0] <= 'z'){
    res = 'a';
  }
  else{
    res = 'A';
  }
  cout << res << endl;
  return 0;
}
