#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n;
char k[2][9];

void init() {
  scanf("%d", &n);
}

bool input() {
  int i;

  if (!n) return false;
  n--;

  scanf("%s", k[0]);
  scanf("%s", k[1]);

  return true;
}

int main() {
  int i, j, a, num[2];

  init();
  while (input()) {
    a = 1;
    for (i = 0; i < 2; i++) {
      num[i] = 0;
      for (j = 0; j < strlen(k[i]); j++) {
        switch (k[i][j]) {
        case 'm':
          num[i] += a * 1000;
          a = 1;
          break;
        case 'c':
          num[i] += a * 100;
          a = 1;
          break;
        case 'x':
          num[i] += a * 10;
          a = 1;
          break;
        case 'i':
          num[i] += a;
          a = 1;
          break;
        default:
          a = k[i][j] - '0';
          break;
        }
        //printf("%d\n", num[i]);
      }

    }
    num[0] += num[1];

    a = num[0] / 1000;
    num[0] %= 1000;
    if (a > 0) {
      if (a > 1) {
        printf("%d", a);
      }
      printf("m");
    }
    a = num[0] / 100;
    num[0] %= 100;
    if (a > 0) {
      if (a > 1) {
        printf("%d", a);
      }
      printf("c");
    }
    a = num[0] / 10;
    num[0] %= 10;
    if (a > 0) {
      if (a > 1) {
        printf("%d", a);
      }
      printf("x");
    }
    a = num[0];
    if (a > 0) {
      if (a > 1) {
        printf("%d", a);
      }
      printf("i");
    }
    printf("\n");

  }

  return 0;
}