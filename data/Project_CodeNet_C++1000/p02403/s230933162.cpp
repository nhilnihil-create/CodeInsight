#include <stdio.h>
 
int main()
{
  int h,w;
  int i,j;
  scanf("%d",&h);
  scanf("%d",&w);
  while(!((h==0) && (w==0))){
    for(i=0;i<h;i++){
      for(j=0;j<w;j++){
        printf("#");
      }
      printf("\n");
    }
    printf("\n");
    scanf("%d",&h);
    scanf("%d",&w);
  }
 
 
  return 0;
}