#include<stdio.h>
int main()
{
	int Health, Attack;
	scanf("%d %d", &Health, &Attack);
	
	if( Health%Attack==0) printf("%d",Health/Attack);
	else if (Health%Attack>0) printf("%d\n",Health/Attack+1);
	
	return 0;
}