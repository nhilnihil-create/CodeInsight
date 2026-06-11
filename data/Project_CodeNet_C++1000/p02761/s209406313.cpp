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

  int number[3];

  for(ii=0;ii<3;ii++){
    number[ii] = -1;
  }

  int s,c;
  bool ngflg;
  ngflg = false;
  
  for(ii=0;ii<m;ii++){

    cin >> s >> c;
    s = s-1;

    if(number[s] == -1 || number[s] == c){
      number[s] = c;
    }
    else{
      number[s] = -2;
      ngflg = true;
    }
    
  }

  if(n >= 2 && number[0] == 0){
    ngflg = true;
  }
  
  if(ngflg){
    cout << -1 << endl;
  }

  else{

    for(ii=0;ii<n;ii++){
      if(number[ii] == -1){
        if(ii == 0 && n != 1){
          cout << 1;
        }
        else{
          cout << 0;
        }
      }
      else{
        cout << number[ii];
      }
    }
    
    cout << endl;

  }

  return 0;
}
