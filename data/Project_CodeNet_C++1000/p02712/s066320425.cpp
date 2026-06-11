#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int64_t n, ans = 0;
  cin >> n;
  rep(i, n + 1) {
    if (i % 3 != 0 && i % 5 != 0) {
      ans += i;
    }
  }
  cout << ans << endl;
}
