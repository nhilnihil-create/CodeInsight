#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;

int main(){
  double n, x[110], y[110], absmax;
  cin>>n;
  absmax = 0;
  for(int i=0; i<n; i++){
    cin>>x[i];
  }
  for(int i=0; i<n; i++){
    cin>>y[i];
  }
  for(int i=1; i<=3; i++){
    double sum = 0, d;
    for(int j=0; j<n; j++){
      sum += pow(abs(x[j]-y[j]), i);
      if (absmax<=abs(x[j]-y[j]) && i==1) absmax = abs(x[j]-y[j]);
    }
    d = pow(sum, 1.0/i);
    printf("%.5f\n", d);
  }
  printf("%5f\n", absmax);
  return 0;
}

