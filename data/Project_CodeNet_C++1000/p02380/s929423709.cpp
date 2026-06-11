#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
 
int main()
{
  double a, b, c;
  double angle, rad;
  double S,L,h;

  cin >> a >> b >> angle;

  rad = angle*M_PI/180;

  h = b * sin(rad);
  S = a * h / 2;
  c = sqrt( pow( h, 2.0) + pow(a-b*cos(rad), 2.0) );
  L = a + b + c;
                         
  
  cout << fixed
    << setprecision(5)
      << S
        << " "
          << L
            << " "
              << h
                << endl;

  return(0);
}