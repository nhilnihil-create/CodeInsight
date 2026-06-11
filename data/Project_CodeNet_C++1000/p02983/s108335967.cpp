#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t L, R;
  cin >> L >> R;
  if(L == 0) {
    cout << 0 << endl;
    return 0;
  }
  else if(R - L == 1) {
    cout << R * L % 2019 << endl;
    return 0;
  }
  else if(R / 673 != L / 673) {
    cout << 0 << endl;
    return 0;  
  }
  else {
    int64_t ans = L * (L + 1) % 2019;
    for(int64_t i = L; i < R; i++) {
      for(int64_t j = i + 1; j <= R; j++) {
        int64_t keep = i * j % 2019;
        if(keep < ans) {
          ans = keep;
        }
      }
    }
    cout << ans << endl;
  }
}