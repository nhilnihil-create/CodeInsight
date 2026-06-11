#include <stdio.h>

int main() {
  int num;
  scanf("%d", &num);
  int a = num * num;
  int b = num * num * num;
  printf("%d", a + b + num);
}