#include<stdio.h>

int main(){
	
	int a;
	int b;
	int c;
	scanf("%d %d %d",&a,&b,&c);
	
	if(a+b+c>=22){
		printf("bust");
	}
	else if(a+b+c<22){
		printf("win");
	}
	
	
	
	
	return 0;
}