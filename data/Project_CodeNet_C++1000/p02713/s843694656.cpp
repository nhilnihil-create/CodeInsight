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


int gcd(int a,int b){
  if(a > b){
    if(a % b == 0){
      return b;
    }
    else{
      return gcd(b,a % b);
    }
  }
  else{
    if(b % a == 0){
      return a;
    }
    else{
      return gcd(a,b % a);
    }
  }
}

int main(){
  lll ii,jj,kk;
  vector<int> ret;
  int k;

  cin >> k;
  lll sum = 0;
  int gcd_ab,gcd_abc;
  for(ii=1;ii<=k;ii++){
    for(jj=1;jj<=k;jj++){
      for(kk=1;kk<=k;kk++){
        gcd_ab = gcd(ii,jj);
        gcd_abc = gcd(gcd_ab,kk);
        sum += gcd_abc;
      }
    }
  }

  cout << sum << endl;
  
  return 0;
}
