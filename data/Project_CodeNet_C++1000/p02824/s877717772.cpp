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
  ll n, m, v, p;
  cin >> n >> m >> v >> p;
  vl a(n);
  rep(i, n) cin >> a[i];
  sort(all(a), greater<ll>());
  ll ok = p - 1, ng = n;
  while(ok + 1 < ng) {
    ll x = (ok + ng) / 2;
    ll now = 0;
    rep(i, n) {
      if(i < p - 1 || x <= i)
        now += m;
      else
        now += m - a[i] + a[x];
    }
    if(a[p - 1] > a[x] + m) now = -1e18;
    if(now < m * v)
      ng = x;
    else
      ok = x;
  }
  cout << ok + 1 << endl;
}