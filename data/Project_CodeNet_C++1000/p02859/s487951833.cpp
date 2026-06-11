#include<stdio.h>
#define PI 3
int main()
{
	int r,area;
	scanf("%d",&r);
	if(1<=r&&r<=100)
	{
	area = (PI*r*r)/(PI*1*1);
	printf("%d\n",area);
	}
	return 0;
}
