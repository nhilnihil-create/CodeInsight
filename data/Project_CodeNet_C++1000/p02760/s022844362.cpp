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

  int a[3][3];
  bool check[3][3];
  memset(check,false,sizeof(check));
  for(ii=0;ii<3;ii++){
    for(jj=0;jj<3;jj++){
      cin >> a[ii][jj] ;
    }
  }

  int n;

  cin >> n;

  vector<int> b(n);

  for(ii=0;ii<n;ii++){
    cin >> b[ii];
  }

  for(kk=0;kk<n;kk++){
    for(ii=0;ii<3;ii++){
      for(jj=0;jj<3;jj++){
        if(b[kk] == a[ii][jj]){
          check[ii][jj] = true;
        }
      }
    }
  }

  //for(ii=0;ii<3;ii++){
  //  for(jj=0;jj<3;jj++){
  //    if(check[ii][jj]){
  //      cout << "○";
  //    }
  //    else{
  //      cout << "×";
  //    }
  //  }
  //  cout << endl;
  //}
  bool bingFlg = false;
  int num = 0;
  // 縦

  for(ii=0;ii<3;ii++){
    num = 0;
    for(jj=0;jj<3;jj++){
      if(check[jj][ii]){
        num++;
      }
    }
    if(num ==  3){
      bingFlg = true;
    }
  }

  //cout << bingFlg << endl;

  // 横
  for(ii=0;ii<3;ii++){
    num = 0;
    for(jj=0;jj<3;jj++){
      if(check[ii][jj]){
        num ++;
      }
    }
    if(num ==  3){
      bingFlg = true;
    }
  }

  // 斜め
  num = 0;
  for(ii=0;ii<3;ii++){

    if(check[ii][ii]){
      num++;
    }
  }
  
  if(num ==  3){
    bingFlg = true;
  }
  //cout << bingFlg << endl;

  num = 0;  
  for(ii=0;ii<3;ii++){

    if(check[2-ii][ii]){
      num++;
    }
  }

  if(num == 3){
    bingFlg = true;
  }

  if(bingFlg){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
  
  return 0;
}
