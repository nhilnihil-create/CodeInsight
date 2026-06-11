#include<stdio.h>
int main(){
	int a;
	int b;
	int c;
	int sum;
	
	scanf("%d %d %d",&a,&b,&c);
	sum=a+b+c;
	if(sum<=21){
		printf("win");
	}
	else{
		printf("bust");
	}
	
	return 0;
}