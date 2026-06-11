#include <stdio.h>
#include <math.h>

int main(){
  double x1,y1,x2,y2;

  scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);

  printf("%f\n",sqrt((pow(x2-x1,2.0)+pow(y2-y1,2.0))));


  return 0;
}

