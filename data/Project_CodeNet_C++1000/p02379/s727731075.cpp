#include<stdio.h>
#include<math.h>
#include<float.h>

int main(){
  double x,y,X,Y,i,j,k,l;
  scanf("%lf %lf %lf %lf",&x,&y,&X,&Y);
  i = X	- x;
  j = Y	- y;
  i = i * i;
  j = j	* j;
  k = i	+ j;
  l = sqrt(k);
  printf("%lf\n",l);
  return 0;
}