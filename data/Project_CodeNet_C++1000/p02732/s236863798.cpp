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
  vector<lll> a(n);
  vector<lll> num(n+1);

  for(ii=0;ii<n;ii++){
    cin >> a[ii];
    num[a[ii]]++;
  }

  lll sum;
  sum = 0;

  for(ii=1;ii<=n;ii++){
    if(num[ii] >= 2){
      sum += num[ii] * (num[ii] -1) / 2;
    }
  }

  //cout << "sum:" << sum << endl;
  lll ans;

  for(ii=0;ii<n;ii++){
    if(num[a[ii]] >= 2){
      ans = sum;
      ans -= num[a[ii]] * (num[a[ii]] -1) / 2;
      ans += (num[a[ii]] -1) * (num[a[ii]] -2) / 2;
    }
    else{
      ans = sum;
    }
    cout << ans << endl;
  }

  return 0;
}
