#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int mod = 1000000007;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
};



// GCD, LCM
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}


vector<ll> fac(3000001); //n!(mod M)
vector<ll> ifac(3000001); //k!^{M-2} (mod M)
//a,bの範囲的にこれだけ配列を用意していけば十分

ll mpow(ll x, ll n){ //x^n(mod M) ←普通にpow(x,n)では溢れてしまうため，随時mod計算
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % mod;
        x = x*x % mod;
        n = n >> 1;
    }
    return ans;
}

ll comb(ll a, ll b){ //aCbをmod計算
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    ll tmp = ifac[a-b]* ifac[b] % mod;
    return tmp * fac[a] % mod;
}




int main() {
  int x,y;
  cin >> x >> y;
  if((x+y)%3!=0){
    cout << 0 << endl;
    return 0;
  }
  int n=(x+y)/3;
  x-=n;y-=n;
  if(x<0||y<0){
    cout << 0 << endl;
    return 0;
  }
  fac[0] = 1;
    ifac[0] = 1;
    for(ll i = 0; i<3000000; i++){
        fac[i+1] = fac[i]*(i+1) % mod; // n!(mod M)
        ifac[i+1] = ifac[i]*mpow(i+1, mod-2) % mod; // k!^{M-2} (mod M) ←累乗にmpowを採用
    }
  cout << comb(n,x) << endl;
}
  