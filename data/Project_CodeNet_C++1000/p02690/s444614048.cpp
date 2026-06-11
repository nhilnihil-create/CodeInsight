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

int main() {
  ll x;
  cin >> x;
  ll n = (1 << 10) + 1;
  rep(i, n) rep(j, n) rep(p, 2) rep(q, 2) {
    ll a = i;
    ll b = j;
    if(p) a *= -1;
    if(q) b *= -1;
    ll now = a * a * a * a * a - b * b * b * b * b;
    if(now != x) continue;
    cout << a << ' ' << b << endl;
    return 0;
  }
}