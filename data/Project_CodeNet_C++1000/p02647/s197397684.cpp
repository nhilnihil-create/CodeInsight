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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector<int> imos(n+1, 0);
  rep(i, k){
    rep(j, n+1){
      imos.at(j) = 0;
    }
    rep(j, n){
      int l = max(0, j - a.at(j));
      int r = min(n, j + a.at(j)+1);
      imos.at(l)++;
      imos.at(r)--;
    }
    int now = 0;
    bool f = false;
    rep(i, n){
      now += imos.at(i);
      a.at(i) = now;
      if(a.at(i) != n) f = true;
    }
    if(f == false) break;
  }
  rep(i, n){
    if(i != 0) cout << " ";
    cout << a.at(i);
  }
  cout << endl;
  return 0;
}