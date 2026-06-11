#include<stdio.h>

int main(){
	
	int a,b,x,y,z;
	scanf("%d",&a);
	b = a%10;
	x = a/10;
	y = x%10;
	z = x/10;
	
	if(b == 7){
		printf("Yes");
	}
	else if(y == 7){
		printf("Yes");
	}
	else if(z == 7){
		printf("Yes");
	}
	else{
		printf("No");
	}
	
	return 0;
}