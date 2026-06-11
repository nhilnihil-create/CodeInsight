#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a.at(i);
  }

  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());

  ll ans = 0;
  ll count = 1;

  ans += a.at(0);
  count++;

  for (long long i = 1; i < n; i++) {
    if (count == n) {
      break;
    }
    ans += a.at(i);
    count++;
    if (count == n) {
      break;
    }
    ans += a.at(i);
    count++;
  }

  cout << ans << endl;
}
