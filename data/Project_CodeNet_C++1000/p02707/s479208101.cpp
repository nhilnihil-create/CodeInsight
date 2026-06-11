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

  int n;
  cin >> n;

  vector<int> a(n);
  a[0] = 0;
  for(ii=1;ii<n;ii++){
    cin >> a[ii] ;
  }
  vector<int> buka(n);

  for(ii=1;ii<n;ii++){
    buka[a[ii]-1]++;
  }

  for(ii=0;ii<n;ii++){
    cout << buka[ii] << endl;
  }
  
  return 0;
}
