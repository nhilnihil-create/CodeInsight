#include<stdio.h>

int main(){
	
	int N;
	int R;
	int K;
	
	scanf("%d %d",&N,&R);
	getchar();
	
	if(N<10){
		printf("%d",100 * (10-N) + R);
	}
	else if  (N>=10){
		printf("%d",R);
	}
	
	return 0;
}