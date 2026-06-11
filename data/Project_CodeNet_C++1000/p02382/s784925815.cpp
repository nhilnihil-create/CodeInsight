#include<iostream>
#include<stdio.h>
#include<cmath>

int main(){
  int n;
  std::cin >> n;

  int x[n];
  int y[n];

  for(int i = 0; i < n; i++){
    std::cin >> x[i];
  }
  for(int i = 0; i < n; i++){
    std::cin >> y[i];
  }

  double d1 = 0, d2 = 0, d3 = 0, dc = 0;
  for(int i = 0; i < n; i++){
    int diff = std::abs(x[i] - y[i]);
    d1 += diff;
    d2 += pow(diff, 2);
    d3 += pow(diff, 3);
    dc = fmax(dc, diff);
  }
  
  printf("%f\n", d1);
  printf("%f\n", sqrt(d2));
  printf("%f\n", pow(d3,  1./ 3));
  printf("%f\n", dc);

  return 0;
}

