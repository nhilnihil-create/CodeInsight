#include<stdio.h>
int main()
{
	int a1,a2,a3;
	int x;
	scanf("%d %d %d",&a1,&a2,&a3);
	x= a1+a2+a3;
	if (x>=22){
		printf("bust");
	}
	else if (x<22){
		printf("win");
	}
	return 0;
}