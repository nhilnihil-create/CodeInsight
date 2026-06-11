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

  lll n,a,b;

  cin >> n >> a >> b;

  lll sum;
  lll mod;
  
  sum = n/(a+b) *a;
  mod = n % (a+b);

  if(mod >= a){
    sum += a;
  }
  else{
    sum += mod;
  }

  cout << sum;
  
  
  return 0;
}
