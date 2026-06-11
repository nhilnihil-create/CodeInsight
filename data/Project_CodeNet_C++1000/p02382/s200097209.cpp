#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main(){

  int n;
  int x[100];
  int y;

  double sum1=0,sum2=0,sum3=0,sumi=0;

  cin >> n;

  for(int i=0; i<n; i++)
    cin >> x[i];

  for(int i=0; i<n; i++){
    cin >> y;
    sum1 += abs(x[i]-y);
    sum2 += (x[i]-y)*(x[i]-y);
    sum3 += abs( (x[i]-y)*(x[i]-y)*(x[i]-y) );

    if(sumi < abs(x[i]-y))
      sumi = abs(x[i]-y);

  }

  printf("%.8lf\n%.8lf\n",sum1, sqrt(sum2) );
  printf("%.8lf\n%.8lf\n", pow(sum3,1.0/3.0), sumi);

  return 0;

}