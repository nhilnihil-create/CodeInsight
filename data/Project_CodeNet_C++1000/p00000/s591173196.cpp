
#include<stdio.h>

int main(){
    int a,b;
 for(a = 1; a < 10; a++)
   {
   for(b = 1;b < 10;b++)
     {
      printf("%d", a);
    printf("x");
  printf("%d", b);
    printf("=");
      printf("%d\n", a*b);
     };
   };
    return 0;
}