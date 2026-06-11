#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  ll k, a, b;
  cin >> k >> a >> b;

  if (b - a >= k) {
    cout << "OK" << endl;
    return 0;
  }

  if (a / k != b / k) {
    cout << "OK" << endl;
    return 0;
  }

  if (a % k == 0 || b % k == 0) {
    cout << "OK" << endl;
    return 0;
  }

  cout << "NG" << endl;
}
