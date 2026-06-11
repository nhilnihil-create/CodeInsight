#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  int m = 0;
  for (char c: s) m = (m + c - '0') % 9;
  if (!m) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  return 0;
}
