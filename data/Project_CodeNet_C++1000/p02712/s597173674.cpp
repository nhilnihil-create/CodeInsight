#include <stdio.h>

int main() {

  int a,i;
  int flag=0;
  long sum=0;
    
  scanf("%d",&a);

  for(i=1;i<=a;i++) {
    if(i%3==0&&i%5==0) {
        flag+=1;
    }
      
    if(i%3==0) {
        flag+=1;
    }
      
    if(i%5==0) {
        flag+=1;
    }
      
    if(flag==0) {
        sum+=i;
    }
      
    flag=0;
  }

  printf("%lld",sum);
  return 0;
}