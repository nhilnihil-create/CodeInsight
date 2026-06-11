#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  vector<int> x(5);
  for (int &x : x) {
    cin >> x;
  }

  for (long i = 0; i < 5; i++) {
    if (x.at(i) == 0) {
      cout << i + 1 << endl;
      return 0;
    }
  }
}
