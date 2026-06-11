#include<stdio.h>

int main(){
  char letter;
  scanf("%c", &letter);
  if(letter >= 'A' && letter <= 'Z'){
    //uppercase
    printf("A\n");
  }
  if(letter >= 'a' && letter <= 'z'){
    //lowercase
    printf("a\n");
  }
  return 0;
}
