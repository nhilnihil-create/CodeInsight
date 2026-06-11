#include<stdio.h>
 
int main(){
  int kazu[32]={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
  int number;
  
  scanf("%d",&number);
  
  printf("%d",kazu[number-1]);
  return 0;
}