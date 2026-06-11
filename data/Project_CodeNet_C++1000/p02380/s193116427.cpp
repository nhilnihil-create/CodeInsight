#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
  double a, b, C, S, L, h, pi=3.14159265358979;
  cin >> a >> b >> C;
  C=C*pi/180;
  h= b * sin(C);
  S = a * h /2;
  L = sqrt(pow(a,2) + pow(b,2) - 2*a*b*cos(C)) + a + b;
  cout << fixed;
  cout << std::setprecision(5) << S << endl << L << endl << h << endl;
  return 0;
}

