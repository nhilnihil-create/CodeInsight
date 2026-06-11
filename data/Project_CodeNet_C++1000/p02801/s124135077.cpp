#include<stdio.h>
#include<string.h>
int main(){
  char C;
  scanf("%c", &C);
  if(C!='z'){
    printf("%c", (int)C+1);
  }else{}
  return 0;
}