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
const int MOD = 1000000007;
using lll = long long;
using ull = unsigned long long;
using namespace std;


int main(){
  lll ii,jj,kk;
  vector<int> ret;
  int n,k;

  cin >> n >> k;

  lll minNum,maxNum;
  lll sum = 0;
  lll cnt;
  for(ii=k;ii<=n+1;ii++){

    minNum = 0;
    maxNum = 0;

    //for(jj=0,cnt=0;jj<ii;jj++,cnt++){
    //  minNum += cnt;
    //  maxNum += (n-cnt);
    //}
    minNum = (ii * (ii-1))/2;
    maxNum = n * ii - minNum;
    //cout << "maxNum:" << maxNum << "minNum:" << minNum << endl;
    
    sum = (sum + maxNum-minNum + 1) % MOD;
  }

  cout << sum << endl;


  return 0;
}
