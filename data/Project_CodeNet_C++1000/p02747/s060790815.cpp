#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  int l = s.size();
  bool hi = true;
  int i = 0;
  while (i < l) {
    if (i + 1 == l) { hi = false; break; }
    if (s[i] != 'h' || s[i + 1] != 'i') { hi = false; break; }
    i += 2;
  }
  if (hi) cout << "Yes\n";
  else cout << "No\n";
  return 0;
}
