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

vl factor(ll n) {
  vl res;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      res.push_back(i);
      if(n / i != i) res.push_back(n / i);
    }
  }
  return res;
}

int main() {
  ll n;
  cin >> n;
  vl f = factor(n);
  ll ans = factor(n - 1).size() - 1;
  for(auto v : f) {
    if(v == 1) continue;
    ll x = n;
    while(x % v == 0) x /= v;
    if(x % v == 1) ans++;
  }
  cout << ans << endl;
}