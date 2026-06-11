#include<stdio.h>

int main()
{
	int a, b;
	scanf("%d %d",&a,&b);
	
	int x = 0;
	for(int i = 1; i < a; i++){
		x += i;
	}
	
	int y = 0;
	for(int j = 1; j < b; j++){
		y += j;
	}
	
	printf("%d",y+x);
	
	
	
	return 0;
}