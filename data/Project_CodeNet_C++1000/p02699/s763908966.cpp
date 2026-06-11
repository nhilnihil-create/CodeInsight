#include <stdio.h>

int main(void)
{
  int s,w;
  
  do {
  	scanf("%d %d",&s,&w);
  } while((s<1 || s>100)||(w<1 || w>100));
  
  if(s>w)
    puts("safe");
  else
    puts("unsafe");
  
  return 0;
}