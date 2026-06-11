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
  vector<int> p;
  int n,k;

  cin >> n >> k;

  p.resize(n);

  for(ii=0;ii<n;ii++){
    cin >>p[ii] ;
  }

  sort(p.begin(),p.end());

  int sum = 0;

  for(ii=0;ii<k;ii++){
    sum += p[ii];
  }

  cout << sum << endl;
  
  return 0;
}
