#include <stdio.h>

int main() {
  int K, A, B;
  scanf("%d %d %d", &K, &A, &B);

  int flag = 0;
  for(int i = A; i <= B; i++) {
    if(i % K == 0) {
      printf("OK");
      flag = 1;
      break;
    }
  }

  if(!flag) {
    printf("NG");
  }
  return 0;
}