#include "bits/stdc++.h"

using namespace std;

using ll = long long;

template <typename T>
void printv(const vector<T> &v) {
  int sz = v.size();
  for (int i = 0; i < sz; i++) {
    cout << v[i] << " \n"[i == sz - 1];
  }
}

ll mypow(ll a, ll b, ll mod) {
  if (b == 0) return 1;
  ll tmp = mypow(a, b / 2, mod);
  if (b % 2)
    return (((tmp * tmp) % mod) * a) % mod;
  else
    return (tmp * tmp) % mod;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, mod;
  cin >> n >> mod;
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  if (mod == 2 || mod == 5) {
    ll ret = 0;
    for (int i = 0; i < n; i++) {
      int num = s[i] - '0';
      if (num % mod == 0) {
        ret += n - i;
      }
    }
    cout << ret << endl;
    return 0;
  }
  s = "$" + s;
  constexpr int MAX_N = 200010;
  vector<ll> sum(MAX_N, 0);
  map<ll, ll> mp;
  ll ten = 1;
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + ten * (s[i] - '0');
    sum[i] %= mod;
    ten = ten * 10 % mod;
    mp[sum[i]]++;
  }
  ll ret = mp[0];
  for (int i = 1; i < n; i++) {
    mp[sum[i]]--;
    ret += mp[sum[i]];
  }
  cout << ret << endl;
}
