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

ll fc(ll l, int c, int d, ll a){
  ll res = a/c + a/d - a/l;
  cerr << res << endl;
  res = a - res;
  return res;
}

int main(){
  ll a, b;
  cin >> a >> b;
  ll c, d;
  cin >> c >> d;
  int g = gcd(c, d);
  ll l = c/g*d;
  a--;
  cout << fc(l, c, d, b) - fc(l, c, d, a) << endl;
  return 0;
}