#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  
  if (s.substr(0, s.size()) == t.substr(0, s.size())) cout << "Yes";
  else cout << "No";
  
  return 0;
}