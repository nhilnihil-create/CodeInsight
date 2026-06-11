#include <iostream>
#include <string>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  short int c = 0;
  for (short int i = 0; i < 3; ++i) {
    if (s[i] == t[i]) ++c;
  }
  cout << c << '\n';
  return 0;
}