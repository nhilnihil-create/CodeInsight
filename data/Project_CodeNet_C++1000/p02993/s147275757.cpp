#include<stdio.h>
int main()
{
	int n=4;
	char a[4];
	for(int i=0;i<n;i++)
	{
		scanf("%c",&a[i]);
	}
	if(a[0]==a[1]||a[1]==a[2]||a[2]==a[3])
	{
		printf("Bad");
	}
	else
	{
		printf("Good");
	}
}