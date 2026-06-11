#include <stdio.h>
int main(){
	
	int K;
	int X;
	int Yen=500;
	
	scanf("%d %d",&K,&X);
	getchar();
	
	if(K*Yen>=X){
		printf("Yes");
	}
	else{
		printf("No");
	}
	return 0;
}