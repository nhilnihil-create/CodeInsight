#include <bits/stdc++.h>
using namespace std;

int main() {
  /*
  cin.tie(0);
  ios::sync_with_stdio(false);
  */
  
  const double pi = 3.1415926535;
  int A, B, H, M;
  cin>>A>>B>>H>>M;
  double d = 6.0*M - (H*60+M)*0.5;
  double rad = (d*pi)/180;
  double x = A*A+B*B-2*A*B*cos(rad);
  double y = sqrt(x);
  printf("%.10lf\n", y);
}