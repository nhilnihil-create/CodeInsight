#include<stdio.h>

int main()
{
	int x, y, j, c;
	scanf("%d %d %d", &x, &y, &j);
	c=x+y+j;
	
	if (c <22){
		printf("win\n");
	}
	else if (c >= 22){
		printf("bust\n");
	}
	return 0;
}