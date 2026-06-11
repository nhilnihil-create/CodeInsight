#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  string s;
  cin >> n >> s;

  vector<int> r, g, b(n, 0);

  rep(i, n) {
    switch (s.at(i)) {
      case 'R': {
        r.push_back(i);
        break;
      }
      case 'G': {
        g.push_back(i);
        break;
      }
      case 'B': {
        b[i] = 1;
        break;
      }
    }
  }

  ll count = r.size() * g.size() * (n - r.size() - g.size());

  for (auto i : r) {
    for (auto j : g) {
      int diff = abs(i - j);
      int fail_a = min(i, j) - diff;
      int fail_b = max(i, j) + diff;
      int fail_c = (i + j) % 2 == 0 ? (i + j) / 2 : -1;

      for (auto fail : {fail_a, fail_b, fail_c}) {
        if (fail >= 0 && fail < n && b[fail] == 1) count--;
      }
    }
  }

  cout << count << endl;

  return 0;
}
