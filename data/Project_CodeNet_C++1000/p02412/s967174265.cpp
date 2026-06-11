#include <stdio.h>

int main (){

     int n[1000], x[1000];
     int a=0;
     int b;
     int c[1000] = {0};

     for (a = 0; a < 1000; a++) {
          scanf ("%d %d", &n[a], &x[a]);
          if (n[a] == 0 && x[a] == 0){
               break;
          }
     }

     for (b = 0; b < a; b++){
          int i, j, k;
          for (i = 1; i < n[b] + 1; i++) {
               for (j = i + 1; j < n[b] + 1; j++) {
                   for (k = j + 1; k < n[b] + 1; k++) {
                        if (x[b] == i + j + k){
                             c[b] = c[b] + 1;
                        }
                   }
                }
           }
           printf("%d\n", c[b]);
      }

     return 0;

}