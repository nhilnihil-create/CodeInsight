#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
 
int main() {
  ll a, b;
  cin >> a >> b;
  ll d = gcd(a, b);
  vector<pair<ll, int>> f;
  for (ll i = 2; i * i <= d; i++) {
    if (d % i) continue;
    f.emplace_back(i, 0);
    while (d % i == 0) {
      d /= i;
      f.back().second++;
    }
  }
  if (d != 1) f.emplace_back(d, 1);
  // rep(i, f.size()) cerr << f[i].first << endl;
  cout << f.size() + 1 << endl;
  return 0;
}