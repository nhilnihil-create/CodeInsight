#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); ++i)
using ll = long long;
using P = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
  int n;
  cin >> n;
  vector<pll> v(n);
  rep(i,n) {
    ll x, l;
    cin >> x >> l;
    v[i] = pll(x-l, x+l);
  }

  sort(v.begin(), v.end(), [](pll a, pll b) {
			     return a.second < b.second;});

  int res = 0;
  ll cur = -(1LL << 60);
  rep(i,n) {
    if (cur > v[i].first) continue;
    ++res;
    cur = v[i].second;
  }
  cout << res << endl;
  return 0;
}
