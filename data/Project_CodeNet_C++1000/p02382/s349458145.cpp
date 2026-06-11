#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
  int n;
  int i;
  double d1=0,d2=0,d3=0,dd=0;
  double *x;
  double *y;
  
  scanf("%d",&n);

  x = (double *)malloc(sizeof(double) * n);
  y = (double *)malloc(sizeof(double) * n);

  for(i=0; i<n; i++){
    scanf("%lf",&x[i]);
  }
  for(i=0; i<n; i++){
    scanf("%lf",&y[i]);
  }

  for(i=0; i<n; i++){
    //d1????°????
    d1 = d1 + fabs(x[i] - y[i]);
    //d2^2????°????
    d2 = d2 + fabs(x[i] - y[i])*fabs(x[i] - y[i]);
    //d3^3????°????
    d3 = d3 + fabs(x[i] - y[i])*fabs(x[i] - y[i])*fabs(x[i] - y[i]);
    //dd????°????
    if(fabs(x[i] - y[i]) > dd){
      dd = fabs(x[i] - y[i]);
    }    
  }

  d2 = sqrt(d2);
  d3 = cbrt(d3);
  
  printf("%f\n",d1);
  printf("%f\n",d2);
  printf("%f\n",d3);
  printf("%f\n",dd);
  
  free(x);
  free(y);
  
  return(0);
}