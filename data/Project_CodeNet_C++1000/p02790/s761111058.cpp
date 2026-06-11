#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, b;
  cin >> a >> b;
  string s, t;
  for(int i=0; i<b; i++) s += to_string(a);
  for(int i=0; i<a; i++) t += to_string(b);
  if (s >= t) cout << t << endl;
  else cout << s << endl; 
}