#include<stdio.h>

int main()
{	
	int x,y,z;
	scanf("%d %d", &x, &y);
	if(x<y){
		printf("1");
	}
	else if(x>=y){
		z=(x-1)/y+1;
		printf("%d", z);
	} 
	return 0;
}