#include <stdio.h>
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	
	if(a==1 && b==2){
		printf("3");
	}
	
	if(a==2 && b==3){
		printf("1");
	}
	
	if(a==3 && b==1){
		printf("2");
	}
	
	if(b==1 && a==2){
	    printf("3");
	}
	
	if(b==2 && a==3){
		printf("1");
	}
	
	if(b==3 && a==1){
		printf("2");
	}

	return 0;
	
}