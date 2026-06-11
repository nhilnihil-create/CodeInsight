#include<stdio.h>

int main(){
  char let;
  scanf("%c", &let);
  if(let >= 'A' && let <= 'Z'){
    printf("A\n");
  }
  else{
    printf("a\n");
  }
  return 0;
}