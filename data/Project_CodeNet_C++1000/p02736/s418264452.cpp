#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<int> xs(n);
  for (int i = 0; i < n; i++) {
    xs[i] = s[i] - '1';
  }

  bool has_one = false;
  for (int i = 0; i < n; i++) {
    if (xs[i] == 1) {
      has_one = true;
    }
  }
  // cout << has_one << endl;
  if (!has_one) {
    for (int i = 0; i < n; i++) {
      xs[i] /= 2;
    }
    int r = 0;
    for (int i = 0; i < n; i++) {
     //  cout << (((n - 1) & i) == i) << endl;
      r += (((n - 1) & i) == i) * (xs[i] % 2);
      r %= 2;
    }
    cout << 2 * r << endl;
  } else {
    int r = 0;
    for (int i = 0; i < n; i++) {
      r += (((n - 1) & i) == i) * (xs[i] % 2);
      r %= 2;
    }
    cout << r << endl;
  }
}