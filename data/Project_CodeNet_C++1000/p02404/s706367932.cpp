#include <stdio.h>
void printAFrame(int y, int x) {
  int i, j;
  for (i = 0; i < x; i++)
    printf("#");
  puts("");
  for (i = 0; i < y - 2; i++) {
    printf("#");
    for (j = 0; j < x - 2; j++) {
      printf(".");
    }
    printf("#\n");
  }
  for (i = 0; i < x; i++)
    printf("#");
  printf("\n\n");
}

int main(void) {
  int H[100000], W[100000];
  int i, j, k, n = 0;

  do {
    scanf("%d %d", &H[n], &W[n]);
    n++;
  } while (!(H[n - 1] == 0 && W[n - 1] == 0));

  // printAFrame(H[0], W[0]);

  for (i = 0; i < n - 1; i++){
    printAFrame(H[i], W[i]);
  }

  return 0;
}