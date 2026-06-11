#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  ll n = static_cast<ll>(s.size());

  ll a = 0;
  ll b = 1;
  vector<ll> vec(2020, 0);
  vec[0] = 1;
  for (ll i = n - 1; 0 <= i; --i) {
    a = (a + b * (s[i] - '0')) % 2019;
    ++vec[a];
    b = (b * 10) % 2019;
  }

  ll ans = 0;
  for (auto &v : vec)
    ans += (v * (v - 1)) / 2;

  cout << ans << endl;
}