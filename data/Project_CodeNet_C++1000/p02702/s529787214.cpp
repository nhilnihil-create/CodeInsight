#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int m = 2019;
  string s;
  cin >> s;
  int n = s.size();
  reverse(s.begin(), s.end());

  ll ans = 0;
  int x = 1, tot = 0;
  vector<int> cnt(m);
  cnt.at(0) = 1;
  rep(i, n) {
    tot += (s.at(i) - '0') * x;
    tot %= m;
    ans += cnt.at(tot);
    cnt.at(tot)++;
    x = (x * 10) % m;
  }

  cout << ans << endl;
  return 0;
}