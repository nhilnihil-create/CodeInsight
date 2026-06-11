#include<stdio.h>

int main()
{
	int x, y, z, hasil;
		scanf("%d %d %d", &x, &y, &z);
		hasil=x+y+z;
		if(hasil < 22){
			printf("win\n");
		}
		else if(hasil >= 22){
			printf("bust\n");
		}
	return 0;	
} 