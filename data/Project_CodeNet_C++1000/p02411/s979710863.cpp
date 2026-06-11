#include<stdio.h>
int main(void)
{
  int m,f,r,j,sum;

  scanf("%d %d %d",&m,&f,&r);

  while(m!=-1 || f!=-1 || r!=-1){
    if(m == -1)sum=0;
    else if(f == -1)sum=0;
    else sum=f+m;
    if(sum >= 80)printf("A\n");
    else if(sum >= 65)printf("B\n");
    else if(sum >= 50)printf("C\n");
    else if(sum >= 30){
      if(r >= 50)printf("C\n");
      else printf("D\n");
    }
    else printf("F\n");
    scanf("%d %d %d",&m,&f,&r);
  }

  return 0;
}