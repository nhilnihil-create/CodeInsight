#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  ll a;
  double b;
  cin >> a >> b;

  cout << long(b * 100 + 0.1) * a / 100 << endl;
}
