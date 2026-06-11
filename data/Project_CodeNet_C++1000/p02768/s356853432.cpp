#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Matrix;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
static const int INF = 2000000000;

const int mod = 1000000007;

ll mod_pow(ll x, ll n){
  ll res = 1;
  while(n > 0){
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}

ll factorial(ll x){
  ll ret = 1;
  while (x){
    ret *= x;
    ret %= mod;
    x--;
  }
  return ret;
}

ll f(ll x, ll a){
  ll ret = 1;
  while (a >= 1){
    ret *= x;
    ret %= mod;
    x--; a--;
  }
  return ret;
}

int main(){
  ll n, a, b;
  cin >> n >> a >> b;
  ll z = mod_pow(2, n);
  z--;
  ll x1 = f(n, a);
  ll x2 = f(n, b);
  ll y1 = factorial(a);
  ll y2 = factorial(b);
  ll w1 = mod_pow(y1, mod - 2);
  ll w2 = mod_pow(y2, mod - 2);
  ll s1 = (x1 * w1) % mod;
  ll s2 = (x2 * w2) % mod;
  ll ans = (z - s1 - s2) % mod;
  if (ans < 0) ans += mod;
  cout << ans << endl;
} 