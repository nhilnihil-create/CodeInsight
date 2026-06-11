#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  for (int i = 0; i < 1000; i++) {
    string t;
    int x = i;
    for (int j = 0; j < 3; j++) {
      t += x % 10 + '0';
      x /= 10;
    }
    int ti = 0;
    for (int j = 0; j < n; j++) {
      if (s.at(j) == t.at(ti)) {
        ti++;
        if (ti == 3) {
          break;
        }
      }
    }
    if (ti == 3) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}