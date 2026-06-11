#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

const long mx = 1e18;

int main() {
  long n;
  cin >> n;

  vector<long> a(n);
  for (long &x : a) {
    cin >> x;
    if (x == 0) {
      cout << 0 << endl;
      return 0;
    }
  }

  long now = 1;
  for (auto x : a) {
    if ((now) > (mx / x) || x * now > mx) {
      now = -1;
      break;
    } else {
      now *= x;
    }
  }
  cout << now << endl;
}
