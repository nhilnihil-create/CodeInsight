#include<stdio.h>

int main(){
  int x[10000],y[10000],i,j,h,w;
  for(i=0;i<10000;i++){
    scanf("%d %d",&x[i],&y[i]);
    if(x[i]==0&&y[i]==0){
      break;
    }
  }
  for(j=0;j<i;j++){
    for(h=0;h<x[j];h++){
      for(w=0;w<y[j];w++){
        printf("#");
      }
      printf("\n");
    }
    printf("\n");
  }

  return 0;
}