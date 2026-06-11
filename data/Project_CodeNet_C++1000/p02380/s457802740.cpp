#include <iostream>
#include <iomanip>
#include <cmath>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::sin;
using std::cos;
using std::fixed;
#define PI 3.141592653589793

int main(void){
  double a,b,c;
  cin >> a >> b >> c;
  double k;//??????????????????
  double S,L,h;
  double rad;
  rad = (c/180) * PI;
  S =a*b*sin(rad)/2;
  k = sqrt(a*a+b*b-2*a*b*cos(rad));

  L = a+b+k;

  h = b*sin(rad);
  cout << fixed;
  cout << setprecision(20) <<  S << endl;
  cout << setprecision(20) <<  L << endl;
  cout << setprecision(20) <<  h << endl;
}