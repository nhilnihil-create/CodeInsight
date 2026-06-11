#include<stdio.h>
int main()
{
	int n,m;
	while(~scanf("%d %d",&n,&m))
	{
		int t=n/(2*m+1);
		if(n%(2*m+1)!=0)
		{
			t++;
		}
	    printf("%d\n",t);
	}
}