#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
//using P = pair<int, int>;

const ll mod = 1000000007;

// mod. m での a の逆元 a^{-1} を計算する
ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

ll pow_kai(ll a, ll n){//aのn乗を計算します。
  ll x = 1;
  while(n > 0){//全てのbitが捨てられるまで。
    if(n&1){//1番右のbitが1のとき。
      x = x*a;
      x %= mod;
    }
    a = a*a;
    a %= mod;
    n >>= 1;//bit全体を右に1つシフトして一番右を捨てる。
  }
  return x;
}

ll choose(ll n, ll r) {
    ll ret = 1;
    for (ll i = n; i > n-r;--i){
        ret *= i;
        ret %= mod;
    }
    for (ll i = 1; i < r+1; ++i) {
        // ret /= i;
        ret %= mod;
        ret = ret * modinv(i,mod) % mod;
    }
    return ret;
}

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = pow_kai(2, n) - 1;
    ans -= choose(n, a);
    ans -= choose(n, b);
    while (ans < 0) ans += mod;
    cout << ans << endl;

    return 0;
}