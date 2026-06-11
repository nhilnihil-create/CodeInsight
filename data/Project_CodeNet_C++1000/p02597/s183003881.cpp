#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

const long long INF = 1000000000000000000 + 7;

int main() {
  ll n;
  cin >> n;
  vector<ll> wcount(n + 1);
  vector<char> ch(n, 0);

  /* cout << n << endl; */
  /* cout << wcount.at(4) << endl; */

  for (long long i = 0; i < n; i++) {
    char c;
    cin >> c;
    ch.at(i) = c;
    if (c == 'W') {
      wcount.at(i + 1) = wcount.at(i) + 1;
    } else {
      wcount.at(i + 1) = wcount.at(i);
    }
  }

  vector<ll> ans(n + 1, INF);

  for (long long i = 0; i < n + 1; i++) {
    ll r = (n - i) - (wcount.at(n) - wcount.at(i));
    ans.at(i) = max(wcount.at(i), r);
  }

  sort(ans.begin(), ans.end());
  cout << ans.at(0) << endl;
}
