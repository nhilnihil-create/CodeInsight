#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

const ll MOD = 26;

int main() {
  ll n;
  cin >> n;

  ll tmp = 0;
  string ans;
  while (true) {
    tmp++;
    if (n - pow(MOD, tmp) > 0) {
      n -= pow(MOD, tmp);
      continue;
    }
    n--;

    while (true) {
      char c = n % MOD + 'a';
      ans = c + ans;
      n /= MOD;
      if (n == 0) {
        if (ans.size() != tmp) {
          ll count = tmp - ans.size();
          for (long i = 0; i < count; i++) {
            ans = 'a' + ans;
          }
        }
        break;
      }
    }
    break;
  }
  cout << ans << endl;
}
