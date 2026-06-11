#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main()
{
  double a, b, c, h, lc;
  cin >> a >> b >> c;
  c = c * 3.14159265 / 180;

  h = b * sin( c );
  lc = sqrt( a * a + b * b - 2 * a * b * cos( c ));

  cout << fixed << setprecision(6) << a * h / 2 << endl;
  cout << fixed << setprecision(6) << a + b + lc << endl;
  cout << fixed << setprecision(6) << h << endl;
  
  return 0;
}