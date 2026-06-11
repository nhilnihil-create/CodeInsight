#include <stdio.h>
int main()
{
  int h,w,sg,g,r,lg;
  scanf("%d %d",&h,&w);
  while(h!=0||w!=0){
    for(sg=0;sg<w;sg++){
      if(h==0){
	break;
	  }
      printf("#");
    }
    printf("\n");
    for(g=0;g<h-2;g++){
      if(w==0){
	break;
	  }
      printf("#");
      for(r=0;r<w-2;r++){
	printf(".");
      }
      printf("#\n");
    }
    for(lg=0;lg<w;lg++){
      if(h==0){
	break;
	  }
      printf("#");
    }
    printf("\n\n");
    scanf("%d %d",&h,&w);
  }
  return 0;
}
      