#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  int x = a*60+b;
  int y = c*60+d;
  cout << y-x-e << endl;
  return 0;
}
