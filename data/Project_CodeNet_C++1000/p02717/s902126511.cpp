#include<stdio.h>

int main() {
  int x,y,z;
  int temp;
  
  scanf("%d %d %d", &x, &y, &z);
  
  temp = x;
  x = y;
  y = temp;
  
  temp = x;
  x = z;
  z = temp;
  
  printf("%d %d %d",x, y, z);
  
  return 0;
}
  