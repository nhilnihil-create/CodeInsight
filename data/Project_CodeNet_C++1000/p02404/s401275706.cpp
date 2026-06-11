#include<stdio.h>
#define N 256

int main(){
  int H[N],W[N];
  int i=0,j,k,l,m,n,h,w;
  while(1){
    scanf("%d %d",&H[i],&W[i]);
    if(H[i]==0 && W[i]==0){
      break;
    }
    i++;
  }
  for(j=0;j<i;j++){
    for(k=0;k<W[j];k++){
      printf("#");
    }
    printf("\n");
    h = H[j]-1;
    w = W[j]-1;
    for(l=1;l<h;l++){
      printf("#");
      for(m=1;m<w;m++){
        printf(".");
      }
      printf("#\n");
    }
    for(n=0;n<W[j];n++){
      printf("#");
    }
    printf("\n\n");
  }
  return 0;
}