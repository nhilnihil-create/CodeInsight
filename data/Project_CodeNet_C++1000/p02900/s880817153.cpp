#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i : x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<pair<ll,int>> factorize(ll n) {
  vector<pair<ll,int>> res;
  for (ll i = 2; i*i <= n; ++i) {
    if (n%i) continue;
    res.emplace_back(i,0);
    while (n%i == 0) {
      n /= i;
      res.back().second++;
    }
  }
  if (n != 1) res.emplace_back(n,1);
  return res;
}

int main() {
  ll A, B;
  cin >> A >> B;
  ll c = __gcd(A, B);
  auto facs = factorize(c);
  int ans = sz(facs) + 1;
  cout << ans << '\n';
  return 0;
}