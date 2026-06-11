#include <cstdio>
#include <cstring>
int main(){
 char ss[301];
 int h,w,i,j;
 while(true){
  scanf("%d %d",&h,&w);
  if((h==0)&&(w==0)) break;
  strcpy(ss,"#");
  for(i=0;i<w-2;i++)    strcat(ss,".");
  strcat(ss,"#\n");
  for(i=0;i<w;i++) printf("#");
  printf("\n");
  for(i=0;i<h-2;i++) printf(ss);
  for(i=0;i<w;i++) printf("#");
  printf("\n\n");
 }
 return 0;
}