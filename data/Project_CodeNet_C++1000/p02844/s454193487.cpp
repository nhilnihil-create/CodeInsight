#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int res = 0;
  for (int x = 0; x <= 999; x++) {
    ostringstream sout;
    sout << setfill('0') << setw(3) << x;
    string xx = sout.str();
    for (int i = 0; i < n; i++) {
      if (s.at(i) != xx.at(0)) {
        continue;
      }
      for (int j = i + 1; j < n; j++) {
        if (s.at(j) != xx.at(1)) {
          continue;
        }
        for (int k = j + 1; k < n; k++) {
          if (s.at(k) == xx.at(2)) {
            res++;
            break;
          }
        }
        break;
      }
      break;
    }
  }
  cout << res << endl;
  return 0;
}
