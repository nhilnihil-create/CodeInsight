#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> b(n - 1);
  rep(i, n - 1) {
    cin >> b.at(i);
  }
  int res = 0;
  rep(i, n) {
    int x;
    if (i == 0) {
      x = b.at(0);
    } else if (i == n - 1) {
      x = b.at(n - 2);
    } else {
      x = min({b.at(i - 1), b.at(i)});
    }
    res += x;
  }
  cout << res << endl;
  return 0;
}
