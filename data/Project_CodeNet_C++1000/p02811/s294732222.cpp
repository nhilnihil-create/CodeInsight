#include<stdio.h>
main()
{
	int V, J; 
	scanf("%d %d", &V, &J);
	
	if (J<=V*500) printf("Yes");
	else if (J>V*500) printf("No");
	
	return 0;	
}