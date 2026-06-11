#include <stdio.h>
void printAChessboard(int h, int w) {
  int i, j, k;

  for (i = 0; i < h / 2; i++) {
    for (j = 0; j < w / 2; j++) {
      printf("#.");
    }
    if (w % 2 == 1)
      printf("#\n");
    else
      printf("\n");

    for (j = 0; j < w / 2; j++) {
      printf(".#");
    }
    if (w % 2 == 1)
      printf(".\n");
    else
      printf("\n");
  }
  if (h % 2 == 1){
    for (j = 0; j < w / 2; j++) {
      printf("#.");
    }
    if (w % 2 == 1)
      printf("#\n");
    else
      printf("\n");
  } else {
    // puts("");
  }
  puts("");
}

int main(int argc, char const *argv[]) {
  int H[100000], W[100000];
  int i, n = 0;

  do {
    scanf("%d %d", &H[n], &W[n]);
    n++;
  } while (!(H[n - 1] == 0 && W[n - 1] == 0));

  for (i = 0; i < n - 1; i++)
    printAChessboard(H[i], W[i]);

  return 0;
}