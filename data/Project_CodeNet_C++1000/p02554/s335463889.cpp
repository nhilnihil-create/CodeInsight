#include "bits/stdc++.h"

#pragma warning(disable : 4996)

typedef long long ll;
#define all(x) (x).begin(), (x).end()  // sortなどの引数を省略
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define max3(x, y, z) max(x, max(y, z))
#define min3(x, y, z) min(x, min(y, z))

using namespace std;
//#define int long long;
#define mod 1000000007
double dist(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
ll idist(ll x1, ll y1, ll x2, ll y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
using namespace std;

signed main() {
  ll a;
  cin >> a;
  ll a10 = 1;
  ll a9 = 1;
  ll a8 = 1;
  if (a==2){
      cout << 2;
      return 0;
  }else if(a==1){
      cout << 0;
      return 0;
  }
  
  rep(i,a){
      a10 *= 10;
      a10 %= mod;
  }
  rep(i,a){
      a9 *= 9;
      a9 %= mod;
  }
  rep(i,a){
      a8 *= 8;
      a8 %= mod;
  }
  ll ans = a10+a8;
  ans %= mod;
  ans -= a9+a9;
  ans += mod+mod;
  ans %= mod;
 cout<< ans;

}
