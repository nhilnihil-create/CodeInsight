#include <stdio.h>

int main(void){
  int a, b;
  char ch;
  while(1){
    scanf("%d",&a);
    getchar();
    ch = getchar();
    scanf("%d",&b);
    if(ch == '?'){
      break;
    }
    switch(ch){
    case '+':
      printf("%d\n",a + b);
      break;
    case '-':
      printf("%d\n",a - b);
      break;
    case '*':
      printf("%d\n",a * b);
      break;
    case '/':
      printf("%d\n",a / b);
      break;
    }
  }
  return 0;
}