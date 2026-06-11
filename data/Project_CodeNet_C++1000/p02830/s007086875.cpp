#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a;
  string s, t, r;
  cin >> a >> s >> t;
  for(int i=0; i<a; i++) {
    r += s[i];
    for(int j=0; j<1; j++) {
      r += t[i];
    }
  }
  cout << r << endl;
  return 0;
}