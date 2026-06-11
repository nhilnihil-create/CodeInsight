#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 1; i <= (n); ++i)
using ll = long long;
using P = pair<int, int>;

ll n, ans, divisor;

int main() {
  cin >> n;
  if (n%2 == 1) {
    ans = 0;
  } else {
    ans = 0;
    divisor = 2;
    rep (i, 25) {
      divisor *= 5;
      ans += n / divisor;
    }
  }
  cout << ans << endl;
  return 0;
}
