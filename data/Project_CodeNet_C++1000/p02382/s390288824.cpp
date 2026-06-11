#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
  int x[100], y[100];
  double d1 = 0.0;
  double d2_1 = 0.0;
  double d3_1 = 0.0;
  double d3;
  double d4_1 = 0.0;

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> x[i];
  for (int i = 1; i <= n; i++) cin >> y[i];

  for (int i = 1; i <= n; i++){
  d1 += fabs(x[i]-y[i]);
  }

  for (int i = 1; i <= n; i++){
  d2_1 += pow(fabs(x[i]-y[i]), 2);
  }
  double d2 = sqrt(d2_1);

  for (int i = 1; i <= n; i++){
  d3_1 += pow(fabs(x[i]-y[i]), 3);
  }
  d3 = pow(d3_1, 1/3.0);

  for (int i = 1; i <= n; i++){
  if (d4_1 <= fabs(x[i]-y[i])) d4_1 = fabs(x[i]-y[i]);
  }

  printf("%lf\n%lf\n%lf\n%lf\n", d1, d2, d3, d4_1);

return 0;
}