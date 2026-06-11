#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int a, b, x;
  cin >> a >> b >> x;
  if (x <= (a * a * b + 0.0) / 2) {
    double h = (x + 0.0) / (b * a);
    h *= 2;
    double m = atan(h / b);
    m /= 3.14159265358979;
    m *= 180;
    m = 90 - m;
    cout << fixed << setprecision(16);
    cout << m << endl;
  }
  else {
    double h = ((b * a * a - x) * 2 + 0.0) / (a * a);
    double m = atan(a / h);
    m /= 3.14159265358979;
    m *= 180;
    m = 90 - m;
    cout << fixed << setprecision(16);
    cout << m << endl;
  } 
}