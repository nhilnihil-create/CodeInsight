#include <stdio.h>

int main(void)
{
  int x,y,z;
  int temp;
  
  do{
    scanf("%d %d %d",&x,&y,&z);
  } while(((x<1 || x>100) || (y<1 || y>100)) || (z<1 || z>100));
  
  temp = x;
  x = y;
  y = temp;
  temp = x;
  x = z;
  z = temp;
  
  printf("%d %d %d\n",x,y,z);
  
  return 0;
}
  