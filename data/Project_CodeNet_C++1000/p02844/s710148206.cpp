#include <bits/stdc++.h>

using namespace std;

template <typename T, typename U>
string zpad(T n, U k) {
  ostringstream ss;
  ss << setw(k) << setfill('0') << n;
  string s(ss.str());
  return s;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  long long ans = 0;
  for (int i = 0; i < 1000; i++) {
    string pass = zpad(i, 3);
    bool f1 = 0, f2 = 0;
    string ss = s;
    for (auto&& c : ss) {
      if (!f1 && pass[0] == c) {
        f1 = 1;
        c = '_';
      };
      if (f1 && !f2 && pass[1] == c) {
        f2 = 1;
        c = '_';
      };
      if (f2 && pass[2] == c) {
        ans++;
        // cerr << pass << endl;
        break;
      };
    }
  }
  cout << ans << '\n';
  return 0;
}