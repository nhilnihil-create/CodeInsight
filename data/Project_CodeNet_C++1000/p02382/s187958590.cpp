#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
  int n;
  double x[110], y[110], d[4]={};

  cin>>n;
  for(int i=0;i<n;i++) cin>>x[i];
  for(int i=0;i<n;i++) cin>>y[i];

  for(int i=0;i<n;i++){
    d[0]+=fabs(x[i]-y[i]);
    d[1]+=pow(fabs(x[i]-y[i]), 2);
    d[2]+=pow(fabs(x[i]-y[i]), 3);
    d[3]=max(d[3], fabs(x[i]-y[i]));
  }

  printf("%f\n%f\n%f\n%f\n", d[0], sqrt(d[1]), cbrt(d[2]), d[3]);
  return 0;
}