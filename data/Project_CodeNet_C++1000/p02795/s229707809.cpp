#include <stdio.h>
 
int main() {
  int rows, column, N, total;
  scanf("%d %d %d", &rows, &column, &N);
  total = (rows > column) ? (N+rows-1)/rows : (N+column-1)/column;
  printf("%d\n", total);
  return 0;
}