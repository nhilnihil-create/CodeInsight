#include<stdio.h>

int main(void) {
  char str[4];
  int i;
  scanf("%s", str);
  for (i = 0; i < 3; i++){
    if(str[i] == str[i+1]){
      printf("Bad\n");
      break;
    } else if(i == 2)
    printf("Good\n");
  }
  return 0;
}