#include <iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int main() {
  int n,x[1000]={},y[1000]={};
  double D2,D3,d1=0,d2=0,d3=0,max=0;
  cin>>n;
  for(int i=0;i<n;i++)cin>>x[i];
  for(int i=0;i<n;i++)cin>>y[i];
  for(int i=0;i<n;i++){
    d1+=fabs(x[i]-y[i]);
    d2+=fabs(x[i]-y[i])*fabs(x[i]-y[i]);
    d3+=pow(fabs(x[i]-y[i]),3);
    if(max<fabs(x[i]-y[i]))max=fabs(x[i]-y[i]);
  }
  D2=sqrt(d2);
  D3=pow(d3,1.0/3.0);
  printf("%.8lf\n%.8lf\n%.8lf\n%.8lf\n",d1,D2,D3,max);
  return 0;
}