#include<stdio.h>
int main()
{
	int d,t,s;
	scanf("%d %d %d",&d,&t,&s);
	if(d<=t*s)printf("Yes");
	else printf("No");
}