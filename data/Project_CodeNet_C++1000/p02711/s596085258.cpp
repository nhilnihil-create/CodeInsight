#include <stdio.h>

int main (){
	int N;
	int a;
	scanf("%d", &N);
	
	a = N / 10;
	
	if ( N % 10 == 7){
		printf("Yes");
	}
	else if ( N / 100 == 7){
		printf("Yes");
	}
	else if ( a % 10 == 7){
		printf("Yes");
	}
	else {
		printf("No");
	}
	 
	return 0;
}