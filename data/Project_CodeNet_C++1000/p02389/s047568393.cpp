#include <stdio.h>

main(void){

int a,b,x;

scanf("%d %d",&a,&b);

x=a*b;

b=2*a+2*b;

a=x;

printf("%d %d\n",a,b);

return 0;

};