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
  lll a,b,n,x;

  cin >> a >> b >> n;

  lll cal;
  lll ans =  (1L << 63);
  ans *= -1;

  //for(ii=1;ii<=n;ii++){
  //  cal = a*ii/b - a * (ii/b);
  //  if(cal > ans){
  //    cout << "ii:" << ii << endl;
  //    ans = cal;
  //  }
  //}
  //ii = b -1;
  //ans = a*ii/b - a * (ii/b);
  // xがb未満の場合大きい法が良い
  if(b > n){
    ii = n;
    ans = a*ii/b - a * (ii/b);
  }
  else{
    ii = b -1;
    ans = a*ii/b - a * (ii/b);    
  }
  
  cout << ans << endl;
  
  return 0;
}
