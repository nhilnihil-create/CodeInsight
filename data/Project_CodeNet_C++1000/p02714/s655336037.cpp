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
  int n;
  string s;
  lll cnt = 0;
  lll k;
  cin >> n;

  cin >> s;

  //for(ii=0;ii<n-2;ii++){
  //  for(jj=ii+1;jj<n-1;jj++){
  //    for(kk=jj+1;kk<n  ;kk++){
  //
  //      //cout << "ii:" << ii << "jj:" << jj << "kk:" << kk << endl;
  //      
  //      if(s[ii] != s[jj] )
  //        if(s[ii] != s[kk])
  //          if(s[jj] != s[kk]){
  //            if(jj - ii != kk - jj){
  //              cnt++;
  //            }
  //          }
  //    }
  //  }
  //}

  lll rgb[3];
  memset(rgb,0,sizeof(rgb));

  for(ii=0;ii<n;ii++){
    if(s[ii] == 'R'){rgb[0]++;}
    if(s[ii] == 'G'){rgb[1]++;}
    if(s[ii] == 'B'){rgb[2]++;}
  }
  lll ans;
  ans = rgb[0] * rgb[1] * rgb[2];
  
  for(jj=0;jj<n;jj++){
    for(ii=0;ii<n;ii++){
      if(jj > ii){
        k = 2*jj - ii;
        if(k < n){
          if(s[ii] == s[jj]){continue;}
          if(s[ii] == s[k]) {continue;}
          if(s[jj] == s[k]) {continue;}
          cnt++;
        }
      }
    }
  }

  cout << ans - cnt << endl;
  
  return 0;
}
