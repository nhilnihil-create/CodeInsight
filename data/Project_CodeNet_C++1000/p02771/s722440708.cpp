#include <stdio.h>

int main()
{
	int P, Q, R;
	scanf("%d %d %d", &P, &Q, &R);
	
	if(P==Q&&P==R&&P==R)
{
	printf("No");
}
	else if(P==Q||P==R||Q==R)
{
	printf("Yes");
}
	else if(P!=Q&&P!=R&&Q!=R)
{
	printf("No");
}
	return 0;
}