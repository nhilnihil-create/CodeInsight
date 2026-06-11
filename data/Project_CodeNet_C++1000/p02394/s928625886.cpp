#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>



int main()
{
   long i,j,k;
   long n;
   long cnt = 0;
   long left,right,mid;
   long ans = 0;
   int W,H,x,y,r;
   scanf("%d",&W);
   scanf("%d",&H);
   scanf("%d",&x);
   scanf("%d",&y);
   scanf("%d",&r);

   if(x+r <= W && 0 <= x-r && 0 <= y-r && y+r <= H)
      printf("Yes\n");
   else
      printf("No\n");


   return 0;
}