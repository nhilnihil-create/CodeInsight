#include <bits/stdc++.h>
using namespace std;

int main() {
  char a, b, c, d;
  cin >> a >> b >> c >> d;
  if((a == b && c == d && a != c) || (a == c && b == d && a != b) ||
     (a == d && b == c && a != b)) cout << "Yes" << endl;
  else cout << "No" << endl;
}