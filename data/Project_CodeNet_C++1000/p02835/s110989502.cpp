#include<stdio.h>
int main()
{
	int a,b,c,x;
	scanf("%d %d %d",&a,&b,&c);
	x=a+b+c;
	if(x>=22){
		printf("bust\n");
	}
	if(x<=21){
		printf("win\n");
	}
	return 0;
}
