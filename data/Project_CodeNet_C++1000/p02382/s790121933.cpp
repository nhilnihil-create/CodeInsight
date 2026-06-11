#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
int main() {
  double *x = new double[1001];
  double *y = new double[1001];
  int i, n;
  long sum2 = 0, sum3 = 0;
  double D1 = 0, D2 = 0, D3 = 0, Dm = 0;
  cin >> n;
  for(i = 0; i < n; i++) {
	cin >> x[i];
  }
  for(i = 0; i < n; i++) {
	cin >> y[i];
  }
  
  for(i = 0; i < n; i++) {
	D1 += abs(x[i] - y[i]);
	
	sum2 += pow(abs(x[i] - y[i]), 2);
	sum3 += pow(abs(x[i] - y[i]), 3);
	
	if(i == 0) {
	  Dm = abs(x[i] - y[i]);
	}
	else {
	  if(abs(x[i] - y[i]) > Dm) {
		Dm = abs(x[i] - y[i]);
	  }
	}
  }
  D2 = sqrt(sum2);
  D3 = cbrt(sum3);
  printf("%lf\n%lf\n%lf\n%lf\n", D1, D2, D3, Dm);
  return 0;
}