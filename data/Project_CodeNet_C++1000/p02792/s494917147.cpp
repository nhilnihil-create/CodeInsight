#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  map<P, int> mp;
  auto f = [&](int x) {
    int a = x % 10;
    int b = 0;
    while (x) {
      b = x;
      x /= 10;
    }
    return P(a, b);
  };
  for (int i = 1; i <= n; i++) {
    P p = f(i);
    mp[p]++;
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    P p = f(i);
    P q(p.second, p.first);
    ans += mp[q];
  }
  cout << ans << endl;
  return 0;
}
