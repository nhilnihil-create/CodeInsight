#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  double a, b, C;
  cin >> a >> b >> C;
  double theta = M_PI*C/180;
  double c = sqrt(a*a + b*b -2*a*b*cos(theta));
  double h = b * sin(theta); 
  double S = a*h/2;
  printf("%0.8f\n", S);
  printf("%0.8f\n", a+b+c);
  printf("%0.8f\n", h);

  return 0;
}