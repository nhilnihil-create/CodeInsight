#include <bits/stdc++.h>
using namespace std;
// (setq-default c-basic-offset 2)

int main() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  string ret = "";
  for (int i = 0; i < n; ++i) {
    ret += s[i];
    ret += t[i];
  }
  cout << ret << endl;

  return 0;
}
