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

  int n,m;


  cin >> n >> m;

  vector<int> a(m);  
  lll sum = 0;
  for(ii=0;ii<m;ii++){
    cin >> a[ii];
    sum += a[ii];
  }
  if(sum <= n){
    cout << (n - sum) << endl;
  }
  else{
    cout << -1 << endl;;
  }
  return 0;
}
