#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <stdio.h>
#define MAXSIZE 101
#define PI 3.141592653589
using namespace std;
int main(){
  int n;
  std::cin >> n;

  int x[1000]={0},y[1000]={0};

  for(int i=0;i<n;i++){
    std::cin >> x[i];
  }
  for(int i=0;i<n;i++){
    std::cin >> y[i];
  }

  double d1=0,d2before=0,d3before=0,d3max=0;
  for(int i=0;i<n;i++){
    d1+=fabs(1.0*x[i]-y[i]);
    d2before+=(x[i]-y[i])*(x[i]-y[i]);
    d3before+=pow(fabs(1.0*x[i]-y[i]),3);
    if(fabs(x[i]-y[i])>d3max)d3max=fabs(x[i]-y[i]);
  }
  printf("%.8f\n",d1);
  printf("%.8f\n",pow(d2before,0.5));
  printf("%.8f\n",pow(d3before,1.0/3));
  printf("%.8f\n",d3max );



}