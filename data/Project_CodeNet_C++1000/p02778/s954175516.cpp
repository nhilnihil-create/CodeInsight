#include <bits/stdc++.h>
using namespace std;
// (setq-default c-basic-offset 2)

int main() {
  string s;
  cin >> s;
  for (char& c : s) {
    c = 'x';
  }
  cout << s << endl;
  return 0;
}
