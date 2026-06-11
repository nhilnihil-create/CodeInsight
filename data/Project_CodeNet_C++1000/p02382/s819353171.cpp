#include <iostream>
#include <math.h>
#include <vector>
#include <stdio.h>
using namespace std;

int main(){
  vector<int> x(1024,0),y(1024,0),dif(1024,0);
  int n,i,p;
  double d=0.0;
  
  cin >> n;
  for( i=0;i<n;i++ ) cin >> x[i];
  for( i=0;i<n;i++ ) cin >> y[i];

  for( p=1;p<=3;p++ ){
    for( i=0;i<n;i++ ){
      d += pow(fabs(x[i]-y[i]),p);
    }
    printf("%.6f\n",pow(d,1.0/p));
    d=0;
  }
  
  for( i=0;i<n;i++ ) dif[i] = fabs(x[i] - y[i]);
  double max=dif[0];
  for( i=0;i<n;i++ ){
    if( max < dif[i] ){
      max = dif[i];
    }
  }
  printf("%.6f\n",max);

  return 0;
}