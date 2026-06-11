#include <stdio.h>

int main()
{
   int w,h,x,y,r;
   scanf("%d %d %d %d %d",&w,&h,&x,&y,&r);
   if(w-r>=x&&r<=x&&h-r>=y&&r<=y){
   	printf("Yes\n");
   }else{
   	printf("No\n");
    }
}
