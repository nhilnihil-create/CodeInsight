#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  double a,b,C;
  cin >> a >> b >> C;
  double S=a*b*sin((C*M_PI)/180.0)/2.0;
  double L=a+b+sqrt(a*a+b*b-2*a*b*cos((C*M_PI)/180.0));
  double h=b*sin((C*M_PI)/180.0);

  cout << fixed << S << endl << L << endl << h << endl;
  return 0;
}