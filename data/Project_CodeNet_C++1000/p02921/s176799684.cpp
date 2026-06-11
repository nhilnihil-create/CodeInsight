#include <bits/stdc++.h>
using namespace std;

int main() {
  
  string s, t;
  cin >> s >> t;
  
  int n = 0;
  
  if (s[0] == t[0]) n += 1;
  if (s[1] == t[1]) n += 1;
  if (s[2] == t[2]) n += 1;
  
  cout << n;
  
}
