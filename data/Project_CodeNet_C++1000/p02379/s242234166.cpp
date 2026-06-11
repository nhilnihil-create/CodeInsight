#include<stdio.h>
#include<math.h>

int main(){
  double a,b,c,d,X,Y,k,x,y;

  scanf("%lf %lf %lf %lf",&a,&b,&c,&d);

  if(a>c){
    x=a-c;
  }else if(a<c){
    x=c-a;
  }
  if(b>d){
    y=b-d;
  }else if(b<d){
    y=d-b;
  }

  X=x*x;
  Y=y*y;
  k=X+Y;

  double z=sqrt(k);

  printf("%f\n",z);

  return 0;
}
  

  
    

  
  