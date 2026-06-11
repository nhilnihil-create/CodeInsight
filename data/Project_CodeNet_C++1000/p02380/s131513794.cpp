#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main(){
  int a,b,C;

  double S,L,h;

  cin >> a >> b >> C;

  double d = C * M_PI /180.0;

  h = b * sin(d);

  double c;
  c = sqrt(a*a+b*b-2*a*b*cos(d));
  L=a+b+c;

  S=a*h/2.0;

  cout << fixed << setprecision(5) << S << endl << fixed << setprecision(5) << L << endl << fixed << setprecision(5) << h << endl;
}