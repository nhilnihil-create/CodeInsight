#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

ll gcd(ll x, ll y) {
  if (y == 0) return x;
  else return gcd(y, x % y);
}

vector<pair<ll, int>> f(ll n) {
  vector<pair<ll, int>> res;
  for (ll i = 2; i*i <= n; i++) {
    if (n%i) continue;
    res.emplace_back(i,0);
    while(n%i == 0) {
      n /= i;
      res.back().second++;
    }
  }
  if (n != 1) res.emplace_back(n,1);
  return res;
}


int main() {
  ll a, b;
  cin >> a >> b;

  ll g = gcd(a,b);
  auto v = f(g);
  int ans = v.size() + 1;
  cout << ans << endl;

}