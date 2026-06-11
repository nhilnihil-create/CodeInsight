#include <bits/stdc++.h>

#define ll long long int

using namespace std;

vector<ll> calc_divisor(ll n) {
  vector<ll> res;
  for (ll i = 1LL; i*i <= n; ++i) {
    if (n % i == 0) {
      res.push_back(i);
      ll j = n / i;
      if (j != i) res.push_back(j);
    }
  }
  sort(res.begin(), res.end());
  return res;
}


int main() {
  ll n;
  cin >> n;
  const auto & div1 = calc_divisor(n-1);
  const auto & div2 = calc_divisor(n);
  ll res = div1.size() - 1;
  for (auto d : div2) {
    if (d == 1) continue;
    ll nn = n;
    while (nn % d == 0) nn /= d;
    if ((nn-1)%d == 0) ++res;
  }
  cout << res << endl;
}
