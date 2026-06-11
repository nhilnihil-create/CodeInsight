#include <stdio.h>

int main()
{
	int N, R;
	scanf("%d%d",&N,&R);
	if(R>4111)
	{
		printf("second value must between 0-4111");
	}
	else if(N>=10)
	{
		printf("%d", R);
	}
	else
	{
		printf("%d", R+100*(10-N));
	}
	return 0;
}