#include <bits/stdc++.h>
using namespace std;
double PI = acos(-1);

int main() {
  int a, b, h, m;
  scanf("%d %d %d %d", &a, &b, &h, &m);
  cout << fixed << setprecision(11);
  //a=>hとmを考慮、1分で0.5度, b=>mだけ考える、1分で6度。
  double x = abs(30*h + 0.5*m - 6*m);
  double deg = x <=180? x: 360-x;
  double cosC = cos(PI*(deg)/180);
  double c = sqrt(a*a + b*b -2*a*b*cosC);
  cout << c;
}