#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;

int main(){
  int n;
  double x[1000], ab[1000];
  double p1=0, p2=0, p3=0, pinf=0;
  cin >> n;
  for(int i=0; i<n; i++) cin >> x[i];
  for(int i=0; i<n; i++){
    cin >> ab[i];
    ab[i] = fabs(ab[i] - x[i]);
    p1 += ab[i];
    p2 += pow(ab[i], 2);
    p3 += pow(ab[i], 3);
    if(ab[i] > pinf) pinf= ab[i];
  }
  p2 = sqrt(p2);
  p3 = pow(p3, 1.0/3.0);
  printf("%f\n%f\n%f\n%f\n", p1, p2, p3, pinf);
  return 0;
}

