#include <stdio.h>
int main() {
	int r,c;
	scanf("%d",&r);
	scanf("%d",&c);
	int N;
	scanf("%d",&N);
	
	if (r < c)
	{
		r = c;
	}
	
	if ( N%r == 0 )
	{
		printf("%d\n",N/r);
	} 
	else if ( N%r != 0)
	{
		printf("%d\n",(N/r)+1);
	}

    return 0;
}