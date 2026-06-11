#include<stdio.h>
void swap (int *x ,int *y){
	int t;
  t = *x;
  *x = *y;
  *y = t;
}
int main (void){
  int X,Y,Z;
  scanf(" %d %d %d",&X,&Y,&Z);
  swap(&X,&Y);
  swap(&X,&Z);
  printf("%d %d %d",X,Y,Z);
}