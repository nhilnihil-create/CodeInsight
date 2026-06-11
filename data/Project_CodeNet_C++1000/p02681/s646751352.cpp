#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using ll = long long;
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  bool no = false;
  rep(i, s.size()) {
    if (s[i] != t[i]) {
      no = true;
    }
  }
  if ((int)s.size() + 1 != (int)t.size()) {
    no = true;
  }
  if (!no) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}