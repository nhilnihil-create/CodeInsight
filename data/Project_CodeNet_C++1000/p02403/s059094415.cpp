#include <stdio.h>

int main(){

  int H,W,i,j,k;
  while(1){
  scanf("%d%d",&H,&W);
  if(H==0&&W==0) break;
  

  for(k=0;k<H;k++){
    for(j=0;j<W;j++){
      printf("#");
     }
     printf("\n");
   }
  printf("\n");
 }
  return 0;
}