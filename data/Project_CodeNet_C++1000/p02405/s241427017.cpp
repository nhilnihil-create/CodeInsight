#include <stdio.h>
int main()
{
  int h,w,r=0,g,cou;
  scanf("%d %d",&h,&w);
  while(h!=0||w!=0){
    while(1){
      while(1){
      if(r<w){
	printf("#");
      }else break;
      r=r+1;
      if(r<w){
	printf(".");
      }else break;
      r=r+1;
      }
    g=g+1;
      if(g>=h){
      break;
      }
      printf("\n");
      r=0;
      while(1){
      if(r<w){
	printf(".");
      }else break;
      r=r+1;
      if(r<w){
	printf("#");
      }else break;
      r=r+1;
	}
    g=g+1;
      if(g>=h){
      break;
      }
      printf("\n");
      r=0;
    }
    printf("\n\n");
    scanf("%d %d",&h,&w);
    r=0;
    g=0;
  }
  return 0;
}
      