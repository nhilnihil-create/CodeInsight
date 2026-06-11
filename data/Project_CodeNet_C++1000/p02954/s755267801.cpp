#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  int size = (int)s.size();
  vector<int> a(size, 1);

  for (int i = 0; i < size; i++) {
    if (!(i + 1 < size)) break;

    if (s[i] == 'R' && s[i + 1] == 'R') {
      a[i + 2] += a[i];
      a[i] = 0;
    }
  }

  for (int i = size - 1; i >= 0; i--) {
    if (!(i - 1 >= 0)) break;

    if (s[i] == 'L' && s[i - 1] == 'L') {
      a[i - 2] += a[i];
      a[i] = 0;
    }
  }

  for (auto b : a) {
    cout << b << ' ';
  }
  cout << '\n';
  return 0;
}