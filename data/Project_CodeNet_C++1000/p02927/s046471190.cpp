#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

int main() {
  int m, d;
  cin >> m >> d;
  int ans = 0;
  for (int i = 22; i <= d; i++) {
    int d1 = i % 10, d10 = i / 10;
    if (d1 < 2) continue;
    if (d1 * d10 <= m) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}