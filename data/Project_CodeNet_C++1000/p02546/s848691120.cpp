#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, result;
  cin >> s;

  if (s[s.length() - 1] == 's') {
    result = s + "es";
  } else {
    result = s + 's';
  }

  cout << result;
}
