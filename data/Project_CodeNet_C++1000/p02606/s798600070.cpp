#include<stdio.h>

int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	int ctr=0;
	for(int i=a;i<=b;i++)
	{
		if(i%c==0)
		{
			ctr++;
		}
	}
	printf("%d\n",ctr);
	return 0;
}