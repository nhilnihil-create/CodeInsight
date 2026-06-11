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

  int a,b;
  int x,y;
  cin >> a >> b;


  for(ii=0;ii<=1000;ii++){

    x = ii * 0.08;
    y = ii * 0.1;

    //cout << "ii:" << ii << "x:" << x << "y:" << y << endl;
    
    if(x == a && y == b){
      
      break;
    }
    
  }
    
  if(ii<=1000){
    cout << ii << endl;
  }
  else{
    cout << -1 << endl;
  }
  return 0;
}
