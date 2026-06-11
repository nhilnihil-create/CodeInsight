#include<stdio.h>
#include<string.h>
void Length(void);

char A[1001], B[1001];

int a[1001][1001];

int n, m;

main(){
  int i, q;

  scanf("%d",&q);

  for(i = 0; i < q; i++){

    scanf("%s", A);

    scanf("%s", B);

    Length();

    printf("%d\n", a[m][n]);
  }

  return 0;
}

void Length(void){

  int i, j;

  m = strlen(A);

  n = strlen(B);

  for(i = 1; i <= m; i++){

    a[i][0] = 0;

  }

  for(j = 0; j <= n; j++){

    a[0][j] = 0;

  }

  for(i = 1; i <= m; i++){
    for(j = 1; j <= n; j++){

      if(A[i-1] == B[j-1])
      a[i][j] = a[i - 1][j - 1] + 1;



      else  if(a[i - 1][j] >= a[i][j-1])

	a[i][j] = a[i - 1][j];

      else a[i][j] = a[i][j -1];
    }
  }
}