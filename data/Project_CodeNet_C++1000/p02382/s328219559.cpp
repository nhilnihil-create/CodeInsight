#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int n, x[101], y[101];
double d1 = 0, d2 = 0, d3 = 0, dm = 0;

int main(){
  cin >> n;
  for(int i = 0; i < n; i++) cin >> x[i];
  for(int i = 0; i < n; i++){
    cin >> y[i];
    d1 += abs(x[i] - y[i]);
    d2 += pow(x[i] - y[i], 2);
    d3 += pow(abs(x[i] - y[i]), 3);
    if(abs(x[i] - y[i]) > dm) dm = abs(x[i] - y[i]);
  }
  printf("%.8f\n%.8f\n%.8f\n%.8f\n", d1, sqrt(d2), pow(d3,  1.0 / 3), dm);
}