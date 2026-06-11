#include<stdio.h>

int main(){
	int n,r,sum;
	scanf("%d %d",&n,&r);
	sum=100*(10-n);
	if (10>=n){
		printf("%d",sum+r);
	}
	else if (n>10){
		printf("%d",r);
	}	
}