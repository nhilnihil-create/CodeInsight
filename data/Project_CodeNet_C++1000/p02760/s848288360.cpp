#include <stdio.h>

int main() {
  int a[3][3], n;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  scanf("%d", &n);

  int b[n];
  for(int i = 0; i < n; i++) {
      scanf("%d", &b[i]);
    
    for(int j = 0; j < 3; j++) {
        for(int k = 0; k < 3; k++) {
            if(b[i] == a[j][k]) {
              a[j][k] = 0;
            }
        }
    }

  }

  if( a[0][0] == 0 && a[0][1] == 0 && a[0][2] == 0 )   printf("Yes");

  else if( a[1][0] == 0 && a[1][1] == 0 && a[1][2] == 0 )  printf("Yes");

  else if( a[2][0] == 0 && a[2][1] == 0 && a[2][2] == 0 )  printf("Yes");

  else if( a[0][0] == 0 && a[1][0] == 0 && a[2][0] == 0 )  printf("Yes");

  else if( a[0][1] == 0 && a[1][1] == 0 && a[2][1] == 0 ) printf("Yes");

  else if( a[0][2] == 0 && a[1][2] == 0 && a[2][2] == 0 ) printf("Yes");

  else if( a[0][0] == 0 && a[1][1] == 0 && a[2][2] == 0 ) printf("Yes");

  else if( a[0][2] == 0 && a[1][1] == 0 && a[2][0] == 0 ) printf("Yes");

  else  printf("No");

  return 0;
}