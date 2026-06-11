#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int64_t H;
  cin >> H;
  int64_t ans = 1;
  while (H > 0) {
    H = floor(H / 2);
    ans *= 2;
  }
  ans--;
  cout << ans << endl;
}