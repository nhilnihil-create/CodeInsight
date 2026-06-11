#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  ll x;
  cin >> x;
  ll n = 100;
  ll count = 0;
  while (n < x) {
    count++;
    n += n / 100;
  }
  cout << count << endl;
}
