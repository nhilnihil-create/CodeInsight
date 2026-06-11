#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < n; ++i)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//~ using P = pair<int, int>;

int main(){
  int n;
  string s;
  cin >> n >> s;

  int cnt=0;
  int ts, flg;
  rep(i, 1000){
    flg=0;
    rep(j, n){
      ts = s[j]-'0';
      if((flg==0 && ts == i/100 %10) ||
         (flg==1 && ts == i/10  %10) ||
         (flg==2 && ts == i/1   %10)) {
        flg++;
        if(flg==3) break;
        else continue;
      }
    }
    
    if(flg==3){
      cnt++;
    }
  }
  cout << cnt << endl;  
  return 0;
}
