#include <bits/stdc++.h>
using namespace std;
int main () {
  string s, t;
  cin >> s >> t;
  int e = s.size();
  int b = t.size();
  int c = 0; int m = 0;
  for (int i = 0; i<= e- b; i++) {
    for (int j = 0 ; j < b ; j++ ) {
      if ( t[j] == s[j+i] ) {
        c++;} }
      m = max(m,c);
      c = 0; }
    cout << b - m; } 