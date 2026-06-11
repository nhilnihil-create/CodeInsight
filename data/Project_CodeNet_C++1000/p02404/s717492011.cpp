#include<stdio.h>
int main(){
  int h,w;
  int i,j;
  scanf("%d %d",&h,&w);
  while(h!=0||w!=0){
    for(i=0;i<h;i++){
      for(j=0;j<w;j++){
	if(i==0||i==h-1||j==0||j==w-1){
	  printf("#");
	}else{
	  printf(".");
	}
      }
      printf("\n");
    }
    printf("\n");
    scanf("%d %d",&h,&w);
  }
  return(0);
}