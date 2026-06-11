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
  string s,t;

  cin >> s >> t;

  int sum = 0;

  for(ii=0;ii<s.size();ii++){
    if(s[ii] != t[ii]){
      sum++;
    }
  }

  cout << sum << endl;
  
  return 0;
}
