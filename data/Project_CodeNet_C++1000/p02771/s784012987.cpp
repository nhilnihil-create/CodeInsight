#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  bool p = 1;
  if(a == b) {
    if(b != c) p = 0;
  }
  else if(b == c || a == c) p = 0;
  if(p) cout << "No" << endl;
  else cout << "Yes" << endl;
}