#include<stdio.h>
int main(void){

  int h,w;
  int i,j;
  int a;
  

  while(1){

    scanf("%d %d",&h,&w);
    if(h==0&&w==0)break;

    for(i=0;i<h;i++){
      for(j=0;j<w;j++){
	(a=i+j);
	if(a%2==1){
	  printf(".");
	}else{
	  printf("#");
	}
      }
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}