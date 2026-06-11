#include <stdio.h>
int main()
{
  int h,w,g,r;
  scanf("%d %d",&h,&w);
  while(h!=0||w!=0){
    for(g=0;g<h;g++){
      for(r=0;r<w;r++){
	printf("#");
      }
      printf("\n");
    }
    printf("\n");
    scanf("%d %d",&h,&w);
  }
  return 0;
}