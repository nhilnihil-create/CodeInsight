#include <bits/stdc++.h>
using namespace std;

int main() {
int x, y, z;
int a, b, c;
cin >> x >> y >> z;
a = x;
b = y;
c = z;
if (a = x) {
  a = y;
  b = x;
}
if (a = y) {
  a = z;
  c = y;
}
cout << a << endl;
cout << b << endl;
cout << c << endl;
	return 0;
}
