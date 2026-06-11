#include<stdio.h>
  int main(void)
{
 int a,b,op,ans;
   while(1)
  {
    scanf("%d %c %d",&a,&op,&b);
      if(op == '+')
    {
      ans=a+b;
      printf("%d\n",ans);
    }
   else if(op == '-')
    {
      ans=a-b;
      printf("%d\n",ans);
    }
   else if(op == '*')
    {
      ans=a*b;
      printf("%d\n",ans);
    }
   else if(op == '/')
    {
      ans=a/b;
      printf("%d\n",ans);
    }
   else if(op == '?')break;
  }

  return 0;
}