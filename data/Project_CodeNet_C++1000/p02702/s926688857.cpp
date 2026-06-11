#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

constexpr ll MOD = 2019;

int main() {
  string s;
  ll n;
  cin >> s;
  n = s.size();

  vector<ll> t(n + 1);

  t[n] = 0;
  ll b = 1;
  for (ll i = n - 1; i >= 0; i--) {
    t[i] = (t[i + 1] + b * (s[i] - '0')) % MOD;
    b = (b * 10) % MOD;
  }

  vector<ll> m(MOD, 0);
  for (ll k = 0; k <= n; k++) {
    m[t[k]]++;
  }

  ll sum = 0;
  for (ll i = 0; i < MOD; i++) {
    sum += m[i] * (m[i] - 1) / 2;
  }

  cout << sum << endl;
}
