#include<stdio.h>

int main()
{
	int x,y,z;
	scanf("%d %d %d", &x, &y, &z);
	if((x==y && x!=z) || (x==z && x!=y) || (y==z && y!=x)){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;	
} 