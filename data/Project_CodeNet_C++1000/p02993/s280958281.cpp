#include<bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  bool ok = true;
  if (s[0] == s[1]) ok = false;
  if (s[1] == s[2]) ok = false;
  if (s[2] == s[3]) ok = false;
  
  if (ok) cout << "Good" << endl;
  else cout << "Bad" << endl;
}