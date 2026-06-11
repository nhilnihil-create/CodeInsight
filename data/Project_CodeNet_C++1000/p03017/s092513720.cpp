#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  int n, a, b, c, d;
  string s;
  cin >> n >> a >> b >> c >> d;
  cin >> s;
  a--;
  b--;
  c--;
  d--;
  s += '#';

  auto find_range = [&](const string& t, int l, int r) {
    auto sub = s.substr(l, r - l + 1 - t.length() + 1);
    if (sub.find(t) == string::npos) return false;
    return true;
  };

  if (find_range("##", b, d) || find_range("##", a, c)) {
    cout << "No" << endl;
    return 0;
  }
  if (c < d) {
    cout << "Yes" << endl;
    return 0;
  }

  bool ok = false;
  for (int i = b; i <= d; i++) {
    if (s[i - 1] == '.' && s[i] == '.' && s[i + 1] == '.') ok = true;
  }
  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
