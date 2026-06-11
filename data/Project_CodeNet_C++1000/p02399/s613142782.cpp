#include <stdio.h>
int main(void) {
int a, b;
scanf("%d",&a);
scanf("%d",&b);
printf("%d %d %lf\n",a/b,a%b,(double)a/b);
return 0;
}