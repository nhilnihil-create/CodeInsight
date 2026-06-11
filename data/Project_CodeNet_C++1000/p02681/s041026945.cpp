#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t, u; cin >> s >> t;
  u = t.substr(0, t.size() - 1);
  if(s == u) cout << "Yes";
  else cout << "No";
}