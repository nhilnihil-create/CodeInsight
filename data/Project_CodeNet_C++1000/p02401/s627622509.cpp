#include <stdio.h>
main(){
  int a,b,c;
  char op;
  scanf("%d %c %d",&a,&op,&b);
  while(op-'?'){
    switch(op){
      case '+':c=a+b;
        break;
      case '-':c=a-b;
        break;
      case '*':c=a*b;
        break;
      case '/':c=a/b;
        break;
    }
    printf("%d\n",c);
    scanf("%d %c %d",&a,&op,&b);
  }
}