#include <bits/stdc++.h>
using namespace std;
 
int main(){
  long double a, b, h, m;
  cin>>a>>b>>h>>m;
  long double theta = M_PI * 2 * (h / 12.0 + (m / 60.0) / 12.0 - m / 60.0);
  long double res=(a*a + b*b - 2*a*b*cos(theta));
  printf("%20.20Lf\n", sqrtl(res));
}