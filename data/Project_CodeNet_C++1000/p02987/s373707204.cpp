#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  string s;
  cin >> s;
  char f, n;
  int fc = 0, nc = 0;
  rep(i, s.size()){
    if(i == 0){
      f = s.at(i);
      fc++;
    }else{
      if(s.at(i) == f) fc++;
      else{
        if(nc == 0){
          nc++;
          n = s.at(i);
        }else if(s.at(i) == n) nc++;
        else{
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }
  if(fc == nc && fc == 2){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}