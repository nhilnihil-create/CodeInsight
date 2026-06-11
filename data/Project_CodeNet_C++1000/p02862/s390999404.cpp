#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using P = pair<int,int>;
using ll = long long;
static const int INF = 1000000000;
static const ll MOD = 1000000007;
ll gcd(ll a, ll b){return b!=0 ? gcd(b, a%b) : a;}
ll lcm(ll a, ll b){return a / gcd(a, b) * b;}

vector<ll> fac(1000001); //n!(mod M)
vector<ll> ifac(1000001); //k!^{M-2} (mod M)
//a,bの範囲的にこれだけ配列を用意していけば十分

ll mpow(ll x, ll n){ //x^n(mod M) ←普通にpow(x,n)では溢れてしまうため，随時mod計算
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % MOD;
        x = x*x % MOD;
        n = n >> 1;
    }
    return ans;
}

ll comb(ll a, ll b){ //aCbをmod計算
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    ll tmp = ifac[a-b] * ifac[b] % MOD;
    return tmp * fac[a] % MOD;
}

int main(){
  int x, y;
  cin >> x >> y;
  if((x + y) % 3 != 0){
    cout << 0 << endl;
    return 0;
  }

  int m = (2 * y - x) / 3;
  int n = (2 * x - y) / 3;
  if(m < 0 || n < 0){
    cout << 0 << endl;
    return 0;
  }

  fac[0] = 1;
  ifac[0] = 1;
  for(ll i = 0; i<1000000; i++){
      fac[i+1] = fac[i]*(i+1) % MOD; // n!(mod M)
      ifac[i+1] = ifac[i]*mpow(i+1, MOD-2) % MOD; // k!^{M-2} (mod M) ←累乗にmpowを採用
  }

  cout << comb(m + n, n) << endl;

  return 0;
}