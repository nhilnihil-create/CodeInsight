#include<stdio.h>
#include<string.h>

int main()
{
	char x[15], y[15], z[15];
	int i,j;
	scanf("%s %s", &x, &y);
	getchar();
	scanf("%d %d", &i, &j);
	getchar();
	scanf("%s", &z);
	
	if(strcmp(x, z)==0){
		printf("%d %d", i-1 , j);
	}
	else if(strcmp(y, z)==0){
		printf("%d %d", i, j-1);
	}
	return 0;
}