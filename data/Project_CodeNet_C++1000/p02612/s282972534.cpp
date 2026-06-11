#include<stdio.h>

int main(){
	int n,a,b;
	scanf("%d", &n);
	a= n%1000;
	b= 1000-a;
	if(b==1000){
		printf("0");
	}
	else{
	printf("%d", b);
	}
	return 0;
}