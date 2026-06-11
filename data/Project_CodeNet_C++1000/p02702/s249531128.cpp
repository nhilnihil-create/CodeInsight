#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// 繰り返し自乗法(x^nをmで割った余り) O(logn)
ll power(ll x, ll n, ll m) {
  ll res = 1;
  if (n > 0) {
    res = power(x, n / 2, m);
    if (n % 2 == 0) res = (res * res) % m;
    else res = (((res * res) % m) * x) % m;
  }
  return res;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  string s;
  cin >> s;
  
  reverse(s.begin(), s.end());
  
  ll keep = 0, ans= 0;
  map<ll, ll> mp;
  mp[0]++;
  for (ll i = 0; i < s.size(); i++) {
    keep += ((s[i] - '0') * power(10, i, 2019)) % 2019;
    keep %= 2019;
    ans += mp[keep];
    mp[keep]++;
  }
  
  cout << ans << '\n';
}