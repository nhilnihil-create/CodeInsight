#include<stdio.h>
int d,t,s;
int main()
{
	scanf("%d%d%d",&d,&t,&s);
	if ((s*t)>=d) printf("Yes");
	else printf("No");
}