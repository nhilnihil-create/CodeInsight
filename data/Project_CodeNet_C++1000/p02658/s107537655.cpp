#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  long n;
  cin >> n;
  long ans = 1;
  for (long i = 0; i < n; i++) {
    long tmp;
    cin >> tmp;

    if (tmp == 0) {
      ans = 0;
    } else if (ans != -1) {
      if (ans > 1000000000000000000 / tmp) {
        ans = -1;
      } else {
        ans *= tmp;
      }
    }
  }

  cout << ans << endl;
}
