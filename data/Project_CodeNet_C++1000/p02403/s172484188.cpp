#include <stdio.h>
int main(void) {
  int H[100000], W[100000];
  int i, j, k, n = 0;

  do {
    scanf("%d %d", &H[n], &W[n]);
    n++;
  } while (!(H[n - 1] == 0 && W[n - 1] == 0));

  for (j = 0; j < H[0]; j++) {
    for (k = 0; k < W[0]; k++) {
      printf("#");
    }
    puts("");
  }

  for (i = 1; i < n; i++) {
    puts("");
    for (j = 0; j < H[i]; j++) {
      for (k = 0; k < W[i]; k++) {
        printf("#");
      }
      puts("");
    }
  }

  return 0;
}