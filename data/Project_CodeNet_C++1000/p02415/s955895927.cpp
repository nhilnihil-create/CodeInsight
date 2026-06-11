#include <iostream>
#include <string>
using namespace std;

bool isLower(char& c) {
  if (c >= 'a' && c <= 'z') return true;
  return false;
}

bool isUpper(char& c) {
  if (c >= 'A' && c <= 'Z') return true;
  return false;
}

void solve() {
  string instr;
  getline(cin, instr);
  for (char& c : instr) {
    char converted;
    int width = 'A' - 'a';

    if (isLower(c)) {
      converted = c + width;
    } else if (isUpper(c)) {
      converted = c - width;
    } else {
      converted = c;
    }
    cout << converted;
  }
  cout << endl;
}

int main() {
  solve();
  return 0;
}

