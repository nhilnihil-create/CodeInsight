#include <bits/stdc++.h>
using namespace std;

bool is_parindrome(string s) {
  int n = s.size();
  for (int i = 0; i < n / 2; i++) {
    if (s.at(i) != s.at(n - i - 1)) return false;
  }
  return true;
}

int main() {
  string s; cin >> s;
  cout << (is_parindrome(s) && is_parindrome(s.substr(0, s.size() / 2)) && is_parindrome(s.substr(s.size() / 2 + 1)) ? "Yes" : "No") << endl;
}