#include <bits/stdc++.h>

using namespace std;

int main() {
  int d;
  string s;
  cin >> d >> s;
  for (auto &c : s) {
    c = (c - 'A' + d) % 26 + 'A';
  }
  cout << s << '\n';
  return 0;
}
