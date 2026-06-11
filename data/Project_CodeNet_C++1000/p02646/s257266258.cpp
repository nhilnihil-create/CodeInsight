#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll a, b;
  long long v, w, t;
  string ans = "NO";
  cin >> a >> v >> b >> w >> t;
  for(ll i = 1; i <= t ;i++) {
    if(a <= b) {
      if((a + i * v) >= (b + i * w)) {
        ans = "YES";
        break;
      }
    } else {
      if((a - i * v) <= (b - i * w)) {
        ans = "YES";
        break;
      }

    }
  }
  cout << ans << endl;
  return 0;
}