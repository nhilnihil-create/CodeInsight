#include<stdio.h>
int main( )
{
	int a;
	scanf("%d",&a);
	int x,y,z,o;
	x=a/1000;
	y=(a-x*1000)/100;
	z=(a-x*1000-y*100)/10;
	o=(a-x*1000-y*100-z*10);
	if(x==y||y==z||z==o)
	{
		printf("Bad\n");
	}
	else
	{
		printf("Good\n");
	}
}