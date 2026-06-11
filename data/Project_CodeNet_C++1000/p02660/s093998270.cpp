#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(ll i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

map<ll, ll> primeFactor(ll n) {
  map<ll, ll> res;
  for(ll i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      res[i]++;
      n /= i;
    }
  }
  if(n != 1) res[n] = 1;
  return res;
}

int main() {
  ll n;
  cin >> n;
  auto pf = primeFactor(n);
  ll ans = 0;
  for(auto v : pf) {
    ll e = v.second;
    ll cnt = 1;
    while(e >= cnt) {
      ans++;
      e -= cnt;
      cnt++;
    }
  }
  cout << ans << endl;
}