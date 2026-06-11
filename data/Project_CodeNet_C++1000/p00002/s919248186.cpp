#include <stdio.h>
int main()
{
  int a,b,sum,cou;
  while( scanf("%d %d",&a,&b)!=EOF ){
    //printf("%d%d",a,b);//
    sum=a+b;
    cou=0;
    while(1){
      if(sum<10)break;
      sum=sum/10;
      cou++;
    }
    printf("%d\n",cou+1);
  }
  return 0;
}