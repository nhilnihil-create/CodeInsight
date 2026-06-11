#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = a; i < (int)(b); i++)
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP1(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
using ll = long long;
int pow(int a, int b, int mod) {
  if (b == 0) {
    return 1;
  } else if (b % 2 == 1) {
    return pow(a, b - 1, mod) * a % mod;
  }
  int c = pow(a, b / 2, mod);
  return c * c % mod;
}
int main() {
  string s;
  cin >> s;
  int n = SZ(s);
  vector<int> mod(n + 1, 0);
  REP(i, n) {
    int num = s[n - 1 - i] - '0';
    mod[n - 1 - i] = (mod[n - i] + num * pow(10, i, 2019)) % 2019;
  }
  map<int, int> cnt;
  REP(i, n + 1) { cnt[mod[i]]++; }
  ll ans = 0;
  for (auto itr = cnt.begin(); itr != cnt.end(); itr++) {
    ll c = itr->second;
    ans += c * (c - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}
