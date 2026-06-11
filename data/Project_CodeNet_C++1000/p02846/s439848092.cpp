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
  ll t1, t2;
  cin >> t1 >> t2;
  ll a1, a2;
  cin >> a1 >> a2;
  ll c1 = a1*t1, c2 = c1 + a2*t2;
  ll b1, b2;
  cin >> b1 >> b2;
  ll d1 = b1*t1, d2 = d1 + b2*t2;
  ll x1, x2, y1, y2;
  if(c1 < d1){
    x1 = c1; x2 = c2;
    y1 = d1; y2 = d2;
  }else{
    x1 = d1; x2 = d2;
    y1 = c1; y2 = c2;
  }
  cerr << y1 << " " << x1 << " : " << x2 << " " << y2 << endl;
  ll h = y1 - x1;
  ll s = x2 - y2;
  if(s < 0) cout << 0 << endl;
  else if(s == 0)cout << "infinity" << endl;
  else if(h % s == 0) cout << h/s*2 << endl;
  else cout << 1 + h/s*2 << endl;
  return 0;
}