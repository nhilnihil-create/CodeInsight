#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  a.push_back(-1e9);
  ll ans = 1000;
  ll tmp = 0, bf = a.at(0);
  bool mode;
  if(a.front() < a.at(1)) mode = true;
  else mode = false;
  rep2(i, 1, n+1){
    // cerr << ans << " " << mode << endl;
    if(mode == false){
      if(a.at(i-1) < a.at(i)){
        bf = a.at(i-1);
        mode = true;
      }
    }else{
      if(a.at(i-1) > a.at(i)){
        tmp = ans/bf * a.at(i-1);
        ans = ans % bf;
        ans += tmp;
        mode = false;
      }
    }
  }
  cout << ans << endl;
  return 0;
}