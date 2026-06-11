#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string a[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
  string s;
  cin >> s;
  rep(i, 7) {
    if (s == a[i]) {
      cout << 7 - i;
      break;
    }
  }
  return 0;
}
