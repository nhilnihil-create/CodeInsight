#include<stdio.h>
int main(void)
{
    int w,h,x,y,r,flg=1;
	scanf("%d %d %d %d %d",&w,&h,&x,&y,&r);
	if(w<x+r||0>x-r) flg=0;
	if(h<y+r||0>y-r) flg=0;
	if(flg==1) printf("Yes\n");
	else printf("No\n");
	return 0;
}