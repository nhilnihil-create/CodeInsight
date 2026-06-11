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

  lll n;

  cin >> n;
  lll ans;

  ans = 0;

  //for(jj=1;jj<=n;jj++){
  //  for(ii=1;ii<=n;ii++){
  //    if(ii % jj == 0){
  //      ans += ii;
  //    }
  //  }
  //}

  ans = 0;
  
  lll k,x;
  lll sum;

  for(ii=1;ii<=n;ii++){

    k = ii;
    x = n/ii;

    sum = k * ( x * ( x + 1) / 2 );

    ans += sum;
    
  }
  
  cout << ans << endl;

  return 0;

}
