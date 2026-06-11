#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
  double a,b,c;
  double s,l ,h;

  cin >> a >> b >> c;
  c = (M_PI/180)*c;
  s = 0.5*a*b*sin(c);
  l = sqrt( a*a+b*b-2*a*b*cos(c));
  l += a+b;
  h = b*sin(c);
  cout << fixed << setprecision(5) << s << endl << l << endl << h << endl;
  return 0;
}