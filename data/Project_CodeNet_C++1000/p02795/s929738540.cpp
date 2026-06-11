#include <stdio.h>
 
int main() {
  int x, y, z, hasil;
  scanf("%d %d %d", &x, &y, &z);
  hasil = (x > y) ? (z+x-1)/x : (z+y-1)/y;
  printf("%d\n", hasil);
  return 0;
}