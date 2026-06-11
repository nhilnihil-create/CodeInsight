#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
  string s;
  cin >> s;
  bool ans = true;
  rep(i, s.size() - 1) {
    if (s.at(i) == s.at(i + 1)) ans = false;
  }
  if (ans == true) cout << "Good" << endl;
  else cout << "Bad" << endl;
}