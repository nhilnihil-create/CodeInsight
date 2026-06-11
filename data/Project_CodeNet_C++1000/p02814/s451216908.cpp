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
  int n, m;
  cin >> n >> m;
  ll l, g;
  vector<ll> a(n);
  int co = 0;
  rep(i, n){
    ll in;
    cin >> in;
    in /= 2;
    if(i == 0){
      a.at(0) = l = g = in;
      while(in % 2 == 0){
        co++;
        in /= 2;
      }
    }else{
      a.at(i) = in;
      g = __gcd(l, in);
      l = l/g*in;
      int tst = 0;
      while(in % 2 == 0){
        tst++;
        in /= 2;
      }
      if(tst != co){
        cout << 0 << endl;
        return 0;
      }
    }
  }
  // cerr << l << endl;
  ll lim = m/l;
  lim++;
  ll ans = lim/2;
  cout << ans << endl;
  return 0;
}