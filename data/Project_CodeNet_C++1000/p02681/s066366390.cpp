#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t; cin >> s >> t;
  cout << (s == t.substr(0, ~-t.length()) ? "Yes" : "No") << endl;
}