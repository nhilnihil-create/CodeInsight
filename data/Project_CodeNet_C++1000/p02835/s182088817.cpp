#include <stdio.h>

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	
	int f = a+b+c ;
	scanf("%d",&f);
	
	int z = 22;
	scanf("%d",&z);
	
	if( f >= z){
		printf("bust");
	}
	else{
		printf("win");
	}
		
	return 0;
	
}