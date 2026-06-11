#include<stdio.h>
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		if(n==0) printf("%d\n",1);
		else if(n==1) printf("%d\n",0);
	}
	return 0;
}