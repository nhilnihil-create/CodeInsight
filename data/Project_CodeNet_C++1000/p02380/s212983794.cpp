#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
using namespace std;


int main(){
  double a,b,c,S;
  cin >> a >> b >> c; 
   c = c*M_PI/180.0;
  S= 0.5*a*b*sin(c);
  cout <<fixed<<setprecision(12) << 0.5*a*b*sin(c) << endl;

  cout <<fixed <<setprecision(12) << a+b+sqrt(pow(a,2)+pow(b,2)-2*a*b*cos(c)) << endl;
  cout <<fixed<<setprecision(12) << 2*S/a << endl;
 }