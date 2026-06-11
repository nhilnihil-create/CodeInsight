#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  char a, b, c, d;
  cin >> S;
  a = S.at(0);
  b = S.at(1);
  c = S.at(2);
  d = S.at(3);
  if ((a==b) || (b==c) || (c==d)) cout << "Bad" << endl;
  else cout << "Good" << endl;
  return 0;
}
