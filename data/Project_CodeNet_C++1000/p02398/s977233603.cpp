#include <stdio.h>
int main(void)
{
  int a=5,b=14,c=80,k=0;
  scanf("%d %d %d",&a,&b,&c);
  for ( ; a <= b; a++){
    if(c % a == 0){
    k++;
    }
  }

  printf("%d\n",k);
  return 0;
}

