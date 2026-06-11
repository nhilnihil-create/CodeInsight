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
  ll n;
  cin >> n;
  vector<P> p;
  rep(i, n) {
    ll x, l;
    cin >> x >> l;
    p.push_back({x + l, x - l});
  }
  ll ans = 0, now = -4e18;
  sort(all(p));
  rep(i, n) {
    if(p[i].second >= now)
      now = p[i].first;
    else
      ans++;
  }
  cout << n - ans << endl;
}