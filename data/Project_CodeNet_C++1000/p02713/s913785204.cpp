#include <bits/stdc++.h>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
using ll = long long;
using d = double;

int main(){
  int k;
  cin >> k;
  int t=0;
  for(int i=1;i<=k;++i){
    for(int j=1;j<=k;++j){
      for(int m=1;m<=k;++m){
        t+=gcd(gcd(i,j),m);
      }
    }
  }
  cout << t << endl;
  return 0;
}