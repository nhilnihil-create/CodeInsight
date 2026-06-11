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

  vector<int> a(n);
  int sum = 0;
  for(ii=0;ii<n;ii++){
    cin >> a[ii];
    sum += a[ii];
  }

  double rate = (1.0d * sum) / (4*m);

  int ok = 0;
  
  for(ii=0;ii<n;ii++){
    if(a[ii] >= rate){
      ok++;
    }
  }

  if(ok >= m){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }

  return 0;
}
