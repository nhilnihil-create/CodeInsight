#include <stdio.h>

int main()
{
  int A, B;
  scanf("%d %d", &A, &B);
  if ( A == 1 && B == 2) {
  	printf("3");
  }
  else if ( A == 2 && B == 1) {
  	printf("3");
  }
  else if ( A == 2 && B == 3) {
  	printf("1");
  }
  else if ( A == 3 && B == 2) {
  printf("1");
  }
  else {
  printf("2");
  }
  return 0;
}