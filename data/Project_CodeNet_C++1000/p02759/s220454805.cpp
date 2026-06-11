#include<stdio.h>

int main(){
	
	int N;
	scanf("%d",&N);
	int x;
	x = N + 1;
	
	if(N%2 == 0){
		printf("%d",N / 2);
	}
	else{
		printf("%d",x / 2);
	}
	
	
	
	
	return 0;
}