#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int main(){

  double a,b,S,L,h;
  double rad;
  double c;


  cin >> a >> b >> c;

  rad = c/180*M_PI;

  S = (a*b*sin(rad))/2;
  L = a + b + sqrt(pow(a,2)+pow(b,2)-2*a*b*cos(rad));
  h = 2*S/a;

  cout << fixed << (a*b*sin(rad))/2 << endl << L << endl << h << endl;


  return 0;
}