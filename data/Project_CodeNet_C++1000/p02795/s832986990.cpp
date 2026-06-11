#include <stdio.h>
 
int main() 
{
  int h, w, n, hasil;
  scanf("%d %d %d", &h, &w, &n);
  hasil = (h > w) ? (n + h-1)/h : (n + w-1)/w;
  printf("%d\n", hasil);
  
  return 0;
}
