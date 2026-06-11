#include<stdio.h>
#include<string.h>
int main(){
  int n,x,i,k,Tscore=0,Hscore=0;
  char T[150],H[150];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s %s",T,H);
    x=strcmp(T,H);
    if(x<0)Hscore+=3;
    else if(x>0)Tscore+=3;
    else Hscore++,Tscore++;
  }
  printf("%d %d\n",Tscore,Hscore);
  return 0;
}