#include <stdio.h>

int main(void)
{
  int a,b,c,d;
  int i;
  
  do {
  	scanf("%d %d %d %d",&a,&b,&c,&d);
  } while((a<1 || a>100)||(b<1 || b>100)||(c<1 || c>100)||(d<1 || d>100));
  
  for(i=0; a>0 && c>0; i++){
    if(i % 2 == 0)
      c -= b;
    else
      a -= d;
  }
      
  if(a<=0)
    puts("No");
  else
    puts("Yes");
  
  return 0;
}
