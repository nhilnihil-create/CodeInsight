#include<stdio.h>
#define N 256

int main(){
  int i=0,j,k=0,m,n;
  int H[N],W[N];
  while(1){
    scanf("%d %d",&H[i],&W[i]);
    if(H[i]==0 && W[i]==0){
      break;
    }
    i++;
  }
  for(m=0;m<i;m++){
    for(j=0;j<H[m];j++){
      for(n=0;n<W[m];n++){
        printf("#");
      }
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}