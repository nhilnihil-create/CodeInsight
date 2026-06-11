#include<stdio.h>

int main()
{
	int x;
	scanf("%d",&x);
	if(x>=400&&x<=599) printf("8\n");
	if(x>=600&&x<=799) printf("7\n");
	if(x>=800&&x<=999) printf("6\n");
	if(x>=1000&&x<=1199) printf("5\n");
	if(x>=1200&&x<=1399) printf("4\n");
	if(x>=1400&&x<=1599) printf("3\n");
	if(x>=1600&&x<=1799) printf("2\n");
	if(x>=1800&&x<=1999) printf("1\n");
	return 0;
 } 