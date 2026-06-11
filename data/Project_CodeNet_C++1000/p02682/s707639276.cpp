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
  lll a,b,c,k;

  cin >> a >> b >> c >> k;

  lll sum  = 0;
  lll rest = k;

  // a
  if(a <= rest){
    sum = a;
    rest -= a;
  }
  else{
    sum = rest;
    rest = 0;
  }
  
  //cout << "sum:" << sum << endl;
  //cout << "rest:" << rest << endl;
  // b
  if( b <= rest){
    rest -= b;
  }
  else{
    rest = 0;
  }

  //cout << "sum:" << sum << endl;
  //cout << "rest:" << rest << endl;
  
  // c
  if( c <= rest){
    sum -= c;
  }
  else{
    sum -= rest;
    rest = 0;
  }
  
  //cout << "sum:" << sum << endl;
  //cout << "rest:" << rest << endl;
  
  cout << sum << endl;
   

  return 0;
}
