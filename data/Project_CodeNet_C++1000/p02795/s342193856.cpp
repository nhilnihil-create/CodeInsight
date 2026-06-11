#include <stdio.h>
 
int main() {
  int c, w, d, result;
  scanf("%d %d %d", &c, &w, &d);
  result = (c > w) ? (d+c-1)/c : (d+w-1)/w;
  printf("%d\n", result);
  return 0;
}