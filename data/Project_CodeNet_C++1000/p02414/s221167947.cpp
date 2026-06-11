#include <stdio.h>

int main(){
  long i, j, k ,l, a, b, c, d, sum = 0;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  int d1[a][b];
  int d2[b][c];
  for(i = 0; i < a; i++) {
    for(j = 0; j < b; j++){
      scanf("%d", &d);
      d1[i][j] = d;
    }
  }
  for(i = 0; i < b; i++) {
    for(j = 0; j < c; j++){
      scanf("%d", &d);
      d2[i][j] = d;
    }
  }
  for(i = 0; i < a; i++) {
    for(j = 0; j < c; j++) {
      for(k = 0; k < b; k++) {
        sum += d1[i][k] * d2[k][j];
      }
      printf("%ld", sum);
      sum = 0;
      if(j < c - 1) {
        printf(" ");
      }
    }
   if(i < a - 1) {
      printf("\n");
    }
  }
  printf("\n");
  return 0;
}

