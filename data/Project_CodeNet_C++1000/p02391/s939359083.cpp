#include<stdio.h>
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	-1000 <= a, 1000 <= b;
	if (a<b){
		printf("a < b\n");
	}
	else if (a>b){
		printf("a > b\n");
	}
	else
		printf("a == b\n");
	return 0;

}