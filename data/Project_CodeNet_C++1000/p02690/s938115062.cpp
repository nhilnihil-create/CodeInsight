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
  for (long long i = -200; i <= 200; i++) {
    for (long long j = -200; j <= 200; j++) {
      ll a = i * i * i * i * i;
      ll b = j * j * j * j * j;
      if (a - b == x) {
        cout << i << " " << j << endl;
        return 0;
      }
    }
  }
}
