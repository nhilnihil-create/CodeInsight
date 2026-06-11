#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s, t;
  cin >> s >> t;
  cout << ((s == t.substr(0, t.size() - 1)) ? "Yes" : "No") << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}