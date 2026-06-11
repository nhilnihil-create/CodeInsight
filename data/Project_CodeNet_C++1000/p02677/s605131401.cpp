#include<iostream>
#include<cmath>
using namespace std;
 
int main() {
  int A,B,H,M;
  cin>>A>>B>>H>>M;
  long double hdeg = 360.L * (60.L*H+M) / 720.L;
  long double mdeg = 360.L * M / 60.L;
  long double deg = hdeg - mdeg;
  if (deg < 0) deg += 360.L;
  if (deg > 180) deg = 360.L - deg;

  long double ans = sqrt(A*A + B*B - 2*A*B*cos(M_PI * deg / 180));
  printf("%.10Lf\n", ans);
  return 0;
}