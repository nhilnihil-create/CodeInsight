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
  lll n,m,k;

  cin >> n >> m >> k;
  vector<int> a,b;
  a.resize(n);
  b.resize(m);

  for(ii=0;ii<n;ii++){
    cin >> a[ii];
  }
  for(ii=0;ii<m;ii++){
    cin >> b[ii];
  }

  //1.Aのみ読む数
  lll sum = 0;
  lll cnt = 0;
  lll aPos = 0;
  lll bPos = 0;

  for(ii=0;ii<n;ii++){
    if(sum + a[ii] <= k){
      sum += a[ii];
      cnt++;
    }
    else{
      break;
    }
    //cout << "sum:" << sum << endl;
  }

  //cout << "cnt:" << cnt << endl;
  aPos = ii -1;
  //cout << "aPos:" << aPos << endl;
  
  //2.Bを読む
  for(ii=0;ii<m;ii++){
    if(sum + b[ii] <= k){
      sum += b[ii];
      cnt++;
    }
    else{
      break;
    }
    //cout << "sum:" << sum << endl;    
  }

  bPos = ii - 1;

  //cout << "cnt:" << cnt << endl;
  //aPos = ii -1;
  //cout << "bPos:" << bPos << endl;
  
  lll max = cnt;

  for(ii=aPos;ii>=0;ii--){

    sum -= a[ii];
    cnt--;

    for(jj=bPos+1;jj<m;jj++){

      if(sum + b[jj] <= k){
        sum += b[jj];
        cnt++;
      }
      else{
        break;
      }

    }
    
    bPos = jj -1;
    
    if(cnt > max){
      max = cnt;
    }
    
  }

  cout << max << endl;
  
  return 0;
}
