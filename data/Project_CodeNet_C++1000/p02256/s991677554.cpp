#include<stdio.h>
int main()
{
  int a,b,r,c;

  scanf("%d %d",&a,&b);

  if(a < b){
    c = a;
    a = b;
    b = c;  
  }
  
  r = a % b;
  
  while(r!=0){
    a = b;
    b = r;
    r = a % b;
  }

  printf("%d\n",b);
  
  return 0;
}
  