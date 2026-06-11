#include <iostream>
#include <cstdio>
#include <cmath>

double MinkovskiDistance(int n, int *x, int *y, double p){
  double sum = 0.0;

  for(int i=0; i<n; i++){
    sum += pow(std::abs(x[i] - y[i]), p);
  }
  return pow(sum, 1/p);
}

double ChebyshevDistance(int n, int *x, int *y){
  double max = 0.0, sub;

  for(int i=0; i<n; i++){
    sub = std::abs(x[i] - y[i]);
    if(sub > max) max = sub;
  }
  return max;
}

int main(){
  int n;
  int x[1000], y[1000];

  std::cin >> n;
  for(int i=0; i<n; i++) std::cin >> x[i];
  for(int i=0; i<n; i++) std::cin >> y[i];

  printf("%.8f\n%.8f\n%.8f\n%.8f\n",
        MinkovskiDistance(n, x, y, 1.0),
        MinkovskiDistance(n, x, y, 2.0),
        MinkovskiDistance(n, x, y, 3.0),
        ChebyshevDistance(n, x, y));
}

