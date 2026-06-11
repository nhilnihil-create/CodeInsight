#include <stdio.h>
   
int main(){

  int val[2] = {0};

    scanf("%d %d", &val[0], &val[1]);

    printf("%d %d %f\n", (int)(val[0] / val[1]), (val[0] % val[1]), ((double)val[0] / (double)val[1]));

  return 0;

}