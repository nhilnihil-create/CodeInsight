#include <stdio.h>
main(void){
  int W,H,x,y,r;
  scanf("%d%d%d%d%d",&W,&H,&x,&y,&r);
  if (y+r <= H && y-r >= 0 && x+r <= W && x-r >= 0){
    printf("Yes\n");
  }
  else printf("No\n");
  return 0;
}