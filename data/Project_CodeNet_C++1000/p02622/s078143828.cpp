#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t; cin >> s >> t;
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    ans += s.at(i) != t.at(i);
  }
  cout << ans << endl;
}