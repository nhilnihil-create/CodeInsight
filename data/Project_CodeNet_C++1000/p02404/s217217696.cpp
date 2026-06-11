#include <stdio.h>

int main(){
  int height[300], weight[300];
  int i = 0, j = 0, count = 0, l = 0;

  for(i=1;i<=300;i++){
    scanf("%d %d", &height[i], &weight[i]);
    if(height[i]==0&&weight[i]==0) break;
    count++;
  }

  for(l=1;l<=count;l++){
    for(i=1;i<=height[l];i++){
      for(j=1;j<=weight[l];j++){
        if(i==1||i==height[l]){
          printf("#");
        }else if(j==1||j==weight[l]){
          printf("#");
        }else{printf(".");}
      }
      printf("\n");
    }
    printf("\n");
  }

  return 0;
}