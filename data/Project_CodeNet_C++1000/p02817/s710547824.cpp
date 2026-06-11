#include <stdio.h>

int main() {
  char input1[100];
  char input2[100];
  
  scanf("%s %s\n", &input1, &input2);
  printf("%s%s", input2, input1);
  
  return 0;
}