#include <stdio.h>
int main(){
  int k,x;
  scanf("%d%d",&k,&x);
  for(int i=k-1; i>0; i--){ printf("%d ",x-i); }
  for(int i=0;   i<k; i++){ printf("%d ",x+i); }
  return 0;
}