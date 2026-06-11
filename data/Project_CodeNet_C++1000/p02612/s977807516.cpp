#include<stdio.h>

int main(){
  int n, change;
  scanf("%d", &n);
  int left = n % 1000;
  if(left > 0){
    change = 1000 - left;
  }
  else{
    change = 0;
  }
  printf("%d\n", change);
  return 0;
}