#include <stdio.h>

int main(void){

  int n,m,i,j;
  scanf("%d %d",&n,&m);

  int A [100][100] ;
  int B [100] ;
  int C [100] = {};

  for (i = 0; i < n; i++){
    for (j = 0; j < m; j++){
      scanf("%d ",&A[i][j]);
    }
  }
  for (i = 0; i < m; i++){
    scanf("%d",&B[i]);
  }

  for (i = 0; i < n; i++){
    for (j = 0; j < m; j++){
      C[i] += A[i][j] * B[j];
    }
    printf("%d\n",C[i]);
  }

  return 0;
}

