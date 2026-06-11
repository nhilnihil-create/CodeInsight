#include<bits/stdc++.h>
using namespace std;

string rever(string s) {
  string t(s.rbegin(), s.rend());
  return t;
}

int main() {
  string s, t, a, b, x, y;
  cin >> s;
  int n = s.size();
  t = rever(s);
  a = s.substr(0, (n-1)/2);
  b = rever(a);
  x = s.substr((n+1)/2);
  y = rever(x);
  if (s==t && a==b && x==y) cout << "Yes" << endl;
  else cout << "No" << endl;
}