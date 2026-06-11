#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int64_t L, R;
  cin >> L >> R;
  if (R - L >= 2018) {
    cout << 0 << endl;
  }
  else {
    int ans = 2020;
    L = L % 2019;
    R = R % 2019;
    for (int i = L; i < R; i++) {
      for (int j = i + 1; j <= R; j++) {
        int memo = (i * j) % 2019;
        ans = min(ans, memo);
        if (ans == 0) {
          break;
        }
      }
    }
    cout << ans << endl;
  }
}