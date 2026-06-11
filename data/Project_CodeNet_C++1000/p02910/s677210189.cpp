#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  bool okay = true;
  for (int i = 0; i < s.size(); ++i) {
    if (i & 1) {
      if (s[i] == 'R') {
        okay = false;
        break;
      }
    }
    else {
      if (s[i] == 'L') {
        okay = false;
        break;
      }
    }
  }
  if (okay) cout << "Yes\n";
  else cout << "No\n";
  return 0;
}