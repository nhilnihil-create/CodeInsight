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

ll n;
vl a, b;
queue<ll> q;

void f(ll i) {
  bool ok;
  if(i == 0) {
    ll m = b[n - 1] + b[1];
    ok = b[0] - a[0] >= m;
  } else if(i == n - 1) {
    ll m = b[n - 2] + b[0];
    ok = b[n - 1] - a[n - 1] >= m;
  } else {
    ll m = b[i - 1] + b[i + 1];
    ok = b[i] - a[i] >= m;
  }
  if(ok) q.push(i);
}

int main() {
  cin >> n;
  a.resize(n);
  b.resize(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  rep(i, n) f(i);
  ll ans = 0;
  while(!q.empty()) {
    ll i = q.front();
    q.pop();
    if(i == 0) {
      ll m = b[n - 1] + b[1];
      ans += (b[i] - a[i]) / m;
      ll r = (b[i] - a[i]) % m;
      b[i] = a[i] + r;
      f(n - 1);
      f(1);
    } else if(i == n - 1) {
      ll m = b[n - 2] + b[0];
      ans += (b[i] - a[i]) / m;
      ll r = (b[i] - a[i]) % m;
      b[i] = a[i] + r;
      f(n - 2);
      f(0);
    } else {
      ll m = b[i - 1] + b[i + 1];
      ans += (b[i] - a[i]) / m;
      ll r = (b[i] - a[i]) % m;
      b[i] = a[i] + r;
      f(i - 1);
      f(i + 1);
    }
  }
  bool ok = true;
  rep(i, n) if(a[i] != b[i]) ok = false;
  if(ok)
    cout << ans << endl;
  else
    cout << -1 << endl;
}