#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int)s.size();
  auto is_batch = [](string s) {
    string rs = s;
    reverse(rs.begin(), rs.end());
    return rs == s;
  };
  bool b1 = is_batch(s);
  bool b2 = is_batch(s.substr(0, (n - 1) / 2));
  bool b3 = is_batch(s.substr((n + 3) / 2 - 1));
  if (b1 && b2 && b3) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }
  return 0;
}
