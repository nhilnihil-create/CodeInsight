#include<stdio.h>
int main (void)
{
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    
    while(1){
    
    if(c-b>0)
        c=c-b;
    
    else{
        printf("Yes\n");
        break;
    }
    
    if(a-d>0)
        a=a-d;
    
    else{
        printf("No\n");
        break;
    }
    }
    
  return 0;
}