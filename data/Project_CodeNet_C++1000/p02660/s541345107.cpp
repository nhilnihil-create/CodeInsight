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


map<int,int> prime_factor(lll n){
  map<int,int> factor;
  lll ii;
  for(ii=2;ii*ii<=n;ii++){
    while( n % ii == 0){
      //cout << "ii" << ii << endl;
      factor[ii]++;
      n = n / ii;
    }
  }
  
  if(n != 1){
    factor[n] = 1;
  }
  
  return factor;
}

int main(){
  lll ii,jj,kk;
  vector<int> ret;

  map<int,int> m;

  lll n ;

  cin >> n;

  m = prime_factor(n);
  lll num,cnt,sum;
  sum = 0;
  for(pair<int,int> p : m){
    //cout << "key:" << p.first << "val:" << p.second << endl;
    num = p.second;
    cnt = 1;

    while(num >= 0){
      num-=cnt;
      cnt+=1;
      if(num >= 0){
       sum++;
      }
    }
    
  }

  cout << sum << endl;
  return 0;
}
