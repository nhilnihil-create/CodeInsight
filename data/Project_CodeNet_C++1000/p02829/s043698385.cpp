#include<stdio.h>
int main (){
	
	int a,b,c;
	
	scanf("%d",&a);
	scanf("%d",&b);
	
	if(a == 1 && b == 2){
		printf("3");
	}
	
	else if(a == 2 && b == 1){
		printf("3");
	}
	
	else if(a == 2 && b == 3){
		printf("1");
	}
	
	else if(a == 3 && b == 2){
		printf("1");
	}
	
	else {
		printf("2");
	}
	
	return 0;
	
}