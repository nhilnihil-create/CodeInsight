#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  int x, n;
  cin >> x >> n;

  set<long> p;

  for (long i = 0; i < n; i++) {
    long tmp;
    cin >> tmp;
    p.insert(tmp);
  }

  long i = 0;
  while (true) {
    if (p.count(x - i) == 0) {
      cout << x - i << endl;
      return 0;
    }
    if (p.count(x + i) == 0) {
      cout << x + i << endl;
      return 0;
    }

    i++;
  }
}
