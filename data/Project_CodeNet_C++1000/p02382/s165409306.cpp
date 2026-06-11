#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
  int n;
  int x[1000] = {}, y[1000] = {};
  double d1 = 0, d2 = 0, d3 = 0, dinf = 0;
  cin >> n;

  for (int i = 0; i<n; i++){
    cin >> x[i];
  }
  for (int i = 0; i<n; i++){
    cin >> y[i];
  }

  for (int i = 0; i<n; i++){
    d1 += fabs(x[i] - y[i]);
    d2 += pow(fabs(x[i]-y[i]),2);
    d3 += pow(fabs(x[i]-y[i]),3);

    if (dinf <= fabs(x[i]-y[i])){
      dinf = fabs(x[i]-y[i]);
    }
  }

  d2 = pow(d2,0.5);
  d3 = pow(d3,1.0/3.0);

  printf("%lf\n%lf\n%lf\n%lf\n", d1, d2, d3, dinf);

  return 0;
}