#include<stdio.h>
int main(){
	int k;
	int x;
	int yen=500;
	int sum;
	
	scanf("%d %d",&k,&x);
	sum=k*yen;
	if(x<=sum){
		printf("Yes");
	}
	else{
		printf("No");
	}
	return 0;
}