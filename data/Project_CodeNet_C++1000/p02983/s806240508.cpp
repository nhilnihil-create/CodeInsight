#include <iostream>
using namespace std;

int main() {
  int L, R;
  cin >> L >> R;

  // naive solution
  // constexpr unsigned long long mod = 2019;
  // int ans = 2019;

  // for (int i = L; i <= R-1; i++) {
  //   for (int j = i+1; j <= R; j++) {
  //     ans = min(ans, (int) ((unsigned long long) (i * j) % mod));
  //   }
  // }

  // cout << ans << endl;

  if (R-L >= 2018) {
    cout << 0 << endl;
    return 0;
  }
  
  constexpr int mod = 2019;
  int ans = 2019;

  L %= mod, R %= mod;

  for (int i = L; i <= R-1; i++) {
    for (int j = i+1; j <= R; j++) {
      ans = min(ans, (i * j) % mod);
    }
  }

  cout << ans << endl;
  return 0;
}