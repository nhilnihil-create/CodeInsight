#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  ll a, b, c, k;
  cin >> a >> b >> c >> k;

  ll remain = k;
  ll sum = 0;
  if (a >= remain) {
    cout << k << endl;
    return 0;
  } else {
    sum += a;
    remain -= a;
  }

  if (b >= remain) {
    cout << sum << endl;
    return 0;
  } else {
    remain -= b;
  }

  cout << sum - remain << endl;
}
