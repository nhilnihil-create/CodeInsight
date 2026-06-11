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
  lll ii,jj,kk,ll,mm;
  vector<int> ret;
  int h,w,k;

  cin >> h >> w >> k;

  int matrix[h][w];
  int tmpm[h][w];
  string tmp;
  
  for(ii=0;ii<h;ii++){
    cin >> tmp;
    for(jj=0;jj<w;jj++){
      if(tmp[jj] == '.'){
        matrix[ii][jj] = 0;
      }
      else{
        matrix[ii][jj] = 1;
      }
    }
  }
  int selecth[h],selectw[w];

  //for(ii=0;ii<pow(2,h);ii++){
  //
  //  for(jj=0;jj<h;jj++){
  //
  //    if( ( (ii >> jj) & 1 ) == 1){
  //      selecth[jj] = 1;
  //    }
  //    else{
  //      selecth[jj] = 0;
  //    }
  //  }
  //  cout << "ii:" << ii << " ";
  //  for(jj=0;jj<h;jj++){
  //    if(selecth[jj] == 1){
  //      cout << jj << ",";
  //    }
  //  }
  //  cout << endl;
  //}


  
  int sum = 0;
  for(ii=0;ii<pow(2,h);ii++){
    for(jj=0;jj<pow(2,w);jj++){

      memcpy(tmpm,matrix,sizeof(tmpm));

      
      for(ll=0;ll<h;ll++){
        if( (( ii >> ll ) & 1) == 1){
          selecth[ll] = 1;
        }
        else{
          selecth[ll] = 0;
        }
      }
      
      for(ll=0;ll<w;ll++){
        if( (( jj >> ll ) & 1) == 1){
          selectw[ll] = 1;
        }
        else{
          selectw[ll] = 0;
        }        
      }

      //同じ行を0
      for(ll=0;ll<h;ll++){
        if(selecth[ll] == 1){
          for(mm=0;mm<w;mm++){
            tmpm[ll][mm] = 0;
          }
        }
      }

      //同じ列を0
      for(ll=0;ll<w;ll++){
        if(selectw[ll] == 1){
          for(mm=0;mm<h;mm++){
            tmpm[mm][ll] = 0;
          }
        }
      }
      int cnt = 0;


      //for(ll=0;ll<h;ll++){
      //  for(mm=0;mm<w;mm++){
      //    cout << tmpm[ll][mm];
      //  }
      //  cout <<  endl;
      //}
      //
      //cout << "=============" << endl;
      for(ll=0;ll<h;ll++){
        for(mm=0;mm<w;mm++){
          if(tmpm[ll][mm] == 1){
            cnt ++;
          }
        }
      }
      //cout << "k:" << k << "cnt:" << cnt << endl;
      if(cnt == k){
        sum++;
      }
      
    }
  }

  cout << sum;
  
  return 0;
}
