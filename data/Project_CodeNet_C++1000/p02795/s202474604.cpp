#include<stdio.h>
#include<math.h>

int main()
{
   int H,W,N,b,c,max ;
    float a,i ;
   scanf("%d %d %d",&H,&W,&N) ;
   if(H>W)
    {
        max=H ;
    }
    else
    {
        max=W ;
    }
   a=N*1.00/max;

   b=(int)a ;
   i=b-a ;
   if(i==0)
    {
        printf("%d",b) ;
    }
    else
    {
        printf("%d",b+1) ;
    }

   return 0 ;
}
