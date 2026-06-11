#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main() {
  int n;
  cin >> n;
  int x[n], y[n];

  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  
  for (int i = 0; i < n; i++) {
    cin >> y[i];
  }

  double d1 = 0;

  for (int i = 0; i < n; i++) {
    d1 += fabs((double)(x[i] - y[i]));
  }
  
  double d2 = 0;

  for (int i = 0; i < n; i++) {
    d2 += pow(fabs((double)(x[i] - y[i])),2);
  }

  d2 = sqrt(d2);
  
  double d3 = 0;

  for (int i = 0; i < n; i++) {
    d3 += pow(fabs((double)(x[i] - y[i])),3);
  }

  d3 = pow(d3, 1 / 3.0);
  
  double dinf = 0;
  double max = 0;
  for (int i = 0; i < n; i++) {
    if (max < fabs(x[i] - y[i])) max = fabs(x[i] - y[i]);
  }
  
  dinf = max;

  printf("%.6f\n%.6f\n%.6f\n%.6f\n" , d1, d2, d3, dinf);
  
  return 0;
}

