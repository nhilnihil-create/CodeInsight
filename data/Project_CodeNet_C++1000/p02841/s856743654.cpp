#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int m1, d1, m2, d2;
  cin >> m1 >> d1 >> m2 >> d2;
  int ans = 0;
  if (m1 + 1 == m2) {
    if (m1 == 2) {
      if (d1 == 28 && d2 == 1) {
        ans = 1;
      }
    } else if (m1 == 4 || m1 == 6 || m1 == 9 || m1 == 11) {
      if (d1 == 30 && d2 == 1) {
        ans = 1;
      }
    } else {
      if (d1 == 31 && d2 == 1) {
        ans = 1;
      }
    }
  }
  cout << ans << endl;
  return 0;
}