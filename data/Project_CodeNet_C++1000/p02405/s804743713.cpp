#include <cstdio>
int main(){
 int i,j,h,w;
 while(true){
  scanf("%d %d",&h,&w);
  if ((h==0)&&(w==0)) break;
  for(i=0;i<h;i++){
   for(j=0;j<w;j++){
    printf((i+j)%2==0?"#":".");
   };
   printf("\n");
  }
  printf("\n");
 }
 return 0;
};