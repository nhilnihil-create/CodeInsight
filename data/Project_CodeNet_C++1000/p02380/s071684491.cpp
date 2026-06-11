#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
  long double a;
  long double b;
  long double c;
  long double s;
  long double l;
  long double h;
  
  cin >> a >> b >> c;
  
  c=c*(M_PI/180.0);
  
  
  s=0.5*a*b*sin(c);
  l=a+b+sqrt(a*a+b*b-2.0*a*b*cos(c));
  h=b*sin(c);
  
  cout << fixed << setprecision(5) << s << "\n";
  cout << fixed << setprecision(5) << l << "\n";
  cout << fixed << setprecision(5) << h << "\n";
}