#include<stdio.h>
int main(void){
  int a;
  char s[101];
  scanf("%d",&a);
  scanf("%s",s);
  if(a>=3200){
    printf("%s\n",s);
  }else{
    printf("red\n");
  }
  return 0;
}