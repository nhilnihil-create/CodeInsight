#include<stdio.h>
int main()
{
	int x,y;
	scanf("%d %d", &x, &y);
	int a=x;
	x=0;
	for(int i=0; i<a; i++){
	x=x+i;	
	}
	int b=y;
	y=0;
	for(int i=0; i<b; i++){
		y=y+i;
	}
	printf("%d", x+y);
	return 0;
}