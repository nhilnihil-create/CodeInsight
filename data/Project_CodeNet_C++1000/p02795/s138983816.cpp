#include<stdio.h>

int main() {
  int a, b, n;
  scanf("%d %d %d", &a, &b, &n);
  if(a < b) a = b;
  printf("%d\n", (n / a) + (n % a != 0));
  return 0;
}