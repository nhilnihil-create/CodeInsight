#include<stdio.h>
int main(){
  int i,h,data[250];
  scanf("%d",&h);
  for(i=0;i<h;++i) scanf("%d",&data[i]);
  for(i=0;i<h;++i){
    printf("node %d:",i+1);
    printf(" key = %d, ",data[i]);
    if(i!=0) printf("parent key = %d, ",data[(i-1)/2]);
    if(i*2+1<h) printf("left key = %d, ",data[i*2+1]);
    if(i*2+2<h) printf("right key = %d, ",data[i*2+2]);
    printf("\n");
  }
  return 0;
}

