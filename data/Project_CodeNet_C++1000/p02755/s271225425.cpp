#include <bits/stdc++.h>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
using ll = long long;
using d = double;

int main(){
  int a,b;
  cin >> a >> b;
  for(int i=0;i<1200;++i){
    bool c8=0,c10=0;
    if(floor(i*8/100)==a){
      c8=1;
    }
    if(floor(i/10)==b){
      c10=1;
    }
    if(c8 && c10){
      return cout << i << endl,0;
    }
    if(i==1199){
      return cout << -1 << endl,0;
    }
  }
  return 0;
}
