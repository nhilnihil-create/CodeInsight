#include <stdio.h>

int main() {
  int K, A, B, objective = 0;
  scanf("%d %d %d", &K, &A, &B);
  
  for(int i = A; i <= B; i++) {
    if(i % K == 0) {
      objective = 1;
      break;
    }
  }

  (objective) ? puts("OK") : puts("NG");
  return 0;
}