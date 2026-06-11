#include <stdio.h>
  
int main() {
  int H , W,i,j;
  
  while(1){
      scanf("%d",&H);/*縦を入力*/
     scanf("%d",&W);/*横を入力*/
    if(H == 0 && W == 0) {/*WとHがともに真の場合*/
      break;  /*ループから抜ける*/
    }
    for(j=1; j<=H; j++) {
      for(i=1; i<=W; i++) {
    printf("#");
      }
      printf("\n");
    }
    printf("\n");
  }
  return 0;
  
}
