#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  int n;
  cin >> n;
  vector<long> a(n);
  for (long &x : a) {
    cin >> x;
  }

  long sum = 0;
  long lmax = 0;

  for (long x : a) {
    lmax = max(lmax, x);
    sum += lmax - x;
  }
  cout << sum << endl;
}
