#include <stdio.h>
int main(void){
 int a,b;
 double f;
 scanf("%d%d",&a,&b);
 
 f=(double)a/b;
 printf("%d %d %lf\n",a/b,a%b,f);
return 0;
}