#include<stdio.h>
#include<math.h>
#define N 256

int main(){
  int H[N],W[N];
  int i=0,j,k,l,m;
  while(1){
    scanf("%d %d",&H[i],&W[i]);
    if(H[i]==0 && W[i]==0){
      break;
    }
    i++;
  }
  for(m=0;m<i;m++){
    for(j=0;j<H[m];j++){
      if(j%2 == 0){
        for(k=0;k<W[m];k++){
	  if(k%2 == 0){
            printf("#");
          }
          if(k%2 == 1){
            printf(".");
          }
        }
      } 
      if(j%2 == 1){
        for(l=0;l<W[m];l++){
	  if(l%2 == 0){
            printf(".");
          }
          if(l%2 == 1){
            printf("#");
          }
        }
      } 
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}