#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

vector<ll> f;

int main() {
  long long n;
  cin >> n;

  f.resize(n + 1, 2);
  f.at(1) = 1;
  for (long long i = 2; i <= n; i++) {
    for (long long j = 2; i * j <= n; j++) {
      f.at(i * j) += 1;
    }
  }

  ll ans = 0;
  for (long long i = 1; i < n + 1; i++) {
    ans += i * f.at(i);
  }
  cout << ans << endl;
}
