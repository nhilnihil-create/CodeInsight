#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main(){
   double a, b, deg, pi, unit, deg_r;
   cin >> a >> b >> deg;
   pi     = 2.0 * asin(1.0);            /* πの値 */
	 unit   = pi / 180.0;                 /* 度 → ラジアン */
   deg_r  = deg * unit;
   double S = 0.5 * a * b * sin(deg_r);
   double L = a + b + sqrt(pow(a,2) + pow(b,2) - 2*a*b*cos(deg_r));
   double h = b * sin(deg_r);
   cout << fixed << setprecision(16);
   cout << S << " " << endl;
   cout << L << " " << endl;
   cout << h << endl;
  }

