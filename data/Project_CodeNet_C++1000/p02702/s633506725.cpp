#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int modpow(int a, int n, int mod) {
  int res = 1;
  while (n) {
    if (n & 1) res = res * a % mod;
    a = (a * a) % mod;
    n >>= 1;
  }
  return res;
}

int main() {
  string s;
  cin >> s;
  int n = s.size();
  vector<int> md(n+1);
  for (int i = n-1; i >= 0; --i) {
    md[i] = (md[i+1] + modpow(10, n-1-i, 2019) * (int)(s[i]-'0')) % 2019;
  }
  vector<int> cnt(2019);
  rep(i, n+1) cnt[md[i]]++;
  ll ans = 0;
  rep(i, 2019) ans += cnt[i] * (cnt[i]-1) / 2;
  cout << ans << endl;
  return 0;
}