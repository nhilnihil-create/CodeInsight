#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, ans = 0, rcnt = 0;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'R') {
      rcnt++;
    }
  }
  for (int i = 0; i < rcnt; i++) {
    if (s[i] == 'W') {
      ans++;
    }
  }
  cout << ans << endl;
}
