#include <stdio.h>
int main()
{
	int N;
	int D;
	int n;
	
	scanf("%d",&N);
	scanf("%d",&D);
	
	if (N%(2*D+1)==0)
	{
		int a = N/(2*D+1);
		printf ("%d",a);
	}	
	else 
	{
		int m = N/(2*D+1)+1;
 		printf("%d",m) ;
	}
}
