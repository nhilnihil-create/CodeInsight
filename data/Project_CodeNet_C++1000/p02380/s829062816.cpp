#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double pi = acos(-1);

double deg2rad(double theta){
  return pi*theta/180.;
}

int main(){
  double a, b, deg;
  double rad, h, c, S, L;

  cin >> a >> b >> deg;

  rad = deg2rad(deg);

  h = b*sin(rad);
  S = a*h/2.;
  c = sqrt(a*a+b*b-2*a*b*cos(rad));
  L = a + b + c;

  cout << fixed << setprecision(8);
  cout << S << endl;
  cout << L << endl;
  cout << h << endl;

}

