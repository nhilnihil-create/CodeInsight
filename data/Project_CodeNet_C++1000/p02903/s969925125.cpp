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
  int h, w, a, b;
  cin >> h >> w >> a >> b;
  rep(i, h){
    bool fi = false;
    if(i >= b) fi = true;
    rep(j, w){
      bool fj = false;
      if(j >= a) fj = true;
      bool o = fj ^ fi;
      cout << o;
    }
    cout << endl;
  }
  return 0;
}