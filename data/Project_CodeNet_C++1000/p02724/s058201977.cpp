#include <stdio.h>

int main(void) {
  int x=0,ans=0;
    scanf("%d",&x);
    while(x>=500)
    {
      x-=500;
      ans+=1000;
    }
    while(x>=5)
    {
      x-=5;
      ans+=5;
    }
    printf("%d",ans);
  return 0;
}