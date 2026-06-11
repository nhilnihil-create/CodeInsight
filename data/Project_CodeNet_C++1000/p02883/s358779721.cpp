#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
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
  ll n, k;
  cin >> n >> k;
  vl a(n), f(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> f[i];
  sort(all(a), greater<ll>());
  sort(all(f));
  ll ng = -1, ok = 1e18;
  while(ng + 1 < ok) {
    ll x = (ng + ok) / 2;
    ll now = 0;
    rep(i, n) {
      ll need = a[i] * f[i] - x;
      if(need <= 0) continue;
      now += (need + f[i] - 1) / f[i];
    }
    if(now <= k)
      ok = x;
    else
      ng = x;
  }
  cout << ok << endl;
}