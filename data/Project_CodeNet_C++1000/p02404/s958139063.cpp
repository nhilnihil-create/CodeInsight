#include <stdio.h>



int main(){
  int W,H,j=0;
  int n = 0;
  int d[10000][2];
  while(j == 0){
    scanf("%d %d",&H,&W);
    if(W == 0 && H == 0){
      j = 1;
    }else{
      d[n][0] = H;
      d[n][1] = W;
      n++;
    }
  }
  for(int i = 0;i < n;i++){ //???????????????????????°??????
    for(int q = 0;q < d[i][0];q++){
      for(j = 0;j < d[i][1];j++){
        if(q == 0 || j == 0 || q == d[i][0]-1 || j == d[i][1]-1){
          printf("#");
        }else{
          printf(".");
        }
      }
      printf("\n");
    }
    printf("\n");
  }
}