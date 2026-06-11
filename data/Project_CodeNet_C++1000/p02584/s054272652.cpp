#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  long x, k, d;
  cin >> x >> k >> d;
  long now = x;
  long count = 0;
  count = (abs(now) + d - 1) / d;
  if (count > k) {
    cout << abs(now) - d * k;
    return 0;
  }

  if ((k - count) % 2 == 0) {
    cout << abs(abs(now) - d * count) << endl;
  } else {
    cout << abs(abs(abs(now) - d * count) - d) << endl;
  }
}
