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

  int n,m,x;

  cin >> n >> m >> x;

  int cost[n];
  int a[n][m];
  

  for(ii=0;ii<n;ii++){
    cin >> cost[ii];
    for(jj=0;jj<m;jj++){
      cin >> a[ii][jj];
    }
  }

  int buy = pow(2,n);

  int goal[m];
  int sum,min;
  min = 1 << 30;
  //cout << min << endl;
  
  for(ii=0;ii<buy;ii++){
    memset(goal,0,sizeof(goal));
    sum = 0;

    for(jj=0;jj<n;jj++){
      if( ((ii >> jj) & 1 ) == 1){
        //cout << "buy:" << jj;
        sum += cost[jj];
        for(kk=0;kk<m;kk++){
          goal[kk] += a[jj][kk];
        }
      }
    }
    // OK Check
    bool flg = true;
    for(jj=0;jj<m;jj++){
      if(goal[jj] < x){
        flg = false;
      }
    }

    if(flg && sum < min){
      min = sum;
    }
    //cout << endl;
    
  }

  if(min != (1 << 30)){
    cout << min << endl;
  }
  else{
    cout << -1 << endl;
  }
  return 0;
}
