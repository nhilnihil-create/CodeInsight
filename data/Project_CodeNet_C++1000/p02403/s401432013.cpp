#include <cstdio>
int main(){
 int i,j,w,h;
 while(true) {
  scanf("%d %d",&h,&w);
  if ((h==0)&&(w==0)) break;
  while(h>0){
   for(i=0;i<w;i++){
    printf("#");
   };
   printf("\n");
   --h;
  }
  printf("\n");
 };
 return 0;
};