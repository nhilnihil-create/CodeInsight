#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

int main() {
  string s;
  cin >> s;
  if (s[s.size() - 1] == 's') {
    cout << s + "es" << endl;
  } else {
    cout << s + "s" << endl;
  }
}
