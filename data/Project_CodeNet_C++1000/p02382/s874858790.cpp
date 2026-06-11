#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#include <cstdlib>
#include <iomanip>
#include <stdio.h>

using namespace std;

int main(){

  int n,x[1000],y[1000];
  double xy=0;

  scanf("%d\n",&n);

  for(int i=0;i<n;i++){
    scanf("%d ",&x[i]);
  }
  for(int i=0;i<n;i++){
    scanf("%d ",&y[i]);
  }

  for(int i=0;i<n;i++){
    xy += (double)abs(x[i] - y[i]);
  }
  printf("%.6lf\n",xy);

  xy=0;
  for(int i=0;i<n;i++){
    xy += pow((double)abs(x[i] - y[i]),2);
  }
  xy=sqrt(xy);
  printf("%.6lf\n",xy);

  xy=0;
  for(int i=0;i<n;i++){
    xy += pow((double)abs(x[i] - y[i]),3);
  }
  xy=cbrt(xy);
  printf("%.6lf\n",xy);

  xy=0;
  for(int i=0;i<n;i++){
    if(xy<(double)abs(x[i] - y[i]))
      xy = (double)abs(x[i] - y[i]);
  }
  printf("%.6lf\n",xy);
}
