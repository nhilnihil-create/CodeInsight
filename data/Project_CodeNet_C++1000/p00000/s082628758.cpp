#include<stdio.h>
int n,m;
int main()
{
 
	for(n=1;n<10;n++)
	{
		for(m=1;m<10;m++)
		{
			printf("%dx%d=%d\n",n,m,n*m);
		}
	}
return 0;
}