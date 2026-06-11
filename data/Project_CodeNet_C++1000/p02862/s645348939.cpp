#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Matrix;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

const int mod = 1000000000+7;

ll factorial(ll x){
  ll ret = 1;
  while (x){
    ret *= x;
    ret %= mod;
    x--;
  }
  return ret;
}

ll mod_pow(ll x, ll n){
  ll res = 1;
  while(n > 0){
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}

int main(){
  ll x, y;
  cin >> x >> y;
  ll s = 2*x - y, t = 2*y - x;
  ll ans;
  if (s >= 0 && t >= 0 && !(s%3) && !(t%3)) {
    ll a = s / 3, b = t / 3;
    ans = factorial(a+b);
    ll c =  ll(factorial(a) * factorial(b)) % mod;
    ans *= mod_pow(c, mod - 2);
    ans %= mod;
  } else {
    ans = 0;
  }
  cout << ans << endl;
}
