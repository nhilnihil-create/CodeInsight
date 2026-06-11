#include <stdio.h>

int main()
{
	int x,y,z;
		scanf("%d %d %d", &x, &y, &z);
	
	if (( x==y && x==z && y==z) || (x!=y && x!=z && y!=z)){
			printf("No");
	}
	else {
		printf("Yes");
	}
	
	return 0;
}