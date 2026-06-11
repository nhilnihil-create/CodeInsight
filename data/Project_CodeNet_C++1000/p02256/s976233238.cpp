#include <stdio.h>

int main(){
  int a,b,ch;
  scanf("%d %d",&a,&b);
  if(a<b){
    ch=a;
    a=b;
    b=ch;
  }
  while(1){
    ch=a%b;
    if(ch==0)break;
    else {
      a=b;
      b=ch;
    }
  }
  printf("%d\n",b);
  return 0;
}