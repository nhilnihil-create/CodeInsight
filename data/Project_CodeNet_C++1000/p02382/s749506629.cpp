#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

void Minkowski_distance(int n, int p, int X[100], int Y[100]){
  double md;

  if ( p == 0 ){
    int max = 0;
    for (int i = 0; i < n; i++) {
      max = (max < fabs(X[i] - Y[i])?(fabs(X[i]-Y[i])):max);
    }
    md = max;
  }
  else {
    double p_power_sum = 0;
    for (int i = 0; i < n; i++) {
      p_power_sum += pow(fabs(X[i]-Y[i]), p);
    }
    md = pow(p_power_sum, 1.0/p);
  }
  printf("%.8f\n", md);
}

int main() {
  int n;
  int X[100]={0}, Y[100]={0};

  cin >> n;
  for (int i = 0; i < n; i++) cin >> X[i];
  for (int i = 0; i < n; i++) cin >> Y[i];

  Minkowski_distance(n, 1, X, Y);
  Minkowski_distance(n, 2, X, Y);
  Minkowski_distance(n, 3, X, Y);
  Minkowski_distance(n, 0, X, Y);
  return 0;
}