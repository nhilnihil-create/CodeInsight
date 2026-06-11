#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;

  vector<int> r(n, 0), g(n, 0), b(n, 0);
  for (int i = n - 1; 0 <= i; --i) {
    if (i != n - 1) {
      r[i] = r[i + 1];
      g[i] = g[i + 1];
      b[i] = b[i + 1];
    }
    switch (s[i]) {
    case ('R'):
      ++r[i];
      break;
    case ('G'):
      ++g[i];
      break;
    case ('B'):
      ++b[i];
      break;
    }
  }

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if (s[i] == s[j])
        continue;

      long long tmp = 0;
      if (s[i] != 'R' && s[j] != 'R') {
        tmp = r[j];
        if (j + (j - i) < n && s[j + (j - i)] == 'R')
          --tmp;
      } else if (s[i] != 'G' && s[j] != 'G') {
        tmp = g[j];
        if (j + (j - i) < n && s[j + (j - i)] == 'G')
          --tmp;
      } else if (s[i] != 'B' && s[j] != 'B') {
        tmp = b[j];
        if (j + (j - i) < n && s[j + (j - i)] == 'B')
          --tmp;
      }

      ans += tmp;
    }
  }
  cout << ans << endl;
}
