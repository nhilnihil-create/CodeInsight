#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
  double a,b,c,deg,S;
  cin >> a >> b >> deg;
  S = (0.5) * a * b * sin(M_PI * deg / 180);
  c = sqrt(a * a + b * b - 2 * a * b * cos(M_PI * deg /180));

  cout << setprecision(10) << S << endl;
  cout << a + b + c << endl;
  cout << 2 * S / a << endl;
}
