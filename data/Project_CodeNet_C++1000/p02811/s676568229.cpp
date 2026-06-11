#include <stdio.h>

int main(){
	int K,X;
	int Yen = 500;
	
	scanf("%d %d", &K,&X);
	
	if(K*Yen>=X){
		printf("Yes");
	}
	else if(K*Yen<=X){
		printf("No");
	}
	return 0;
}