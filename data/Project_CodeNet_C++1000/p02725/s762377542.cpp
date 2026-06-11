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
  int k,n;

  cin >> k >> n;

  vector<int> a(n);

  for(ii=0;ii<n;ii++){
    cin >> a[ii];
  }
  
  int dist,maxDist;
  maxDist = -1;
  for(ii=1;ii<n;ii++){
    dist = a[ii] - a[ii-1];
    if(dist > maxDist){
      maxDist = dist;
    }
                      
  }
  
  dist = k - a[n-1] + a[0];
  if(dist > maxDist){
    maxDist = dist;
  }

  cout << k - maxDist << endl;
  
  return 0;
}
