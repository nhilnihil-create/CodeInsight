#include<stdio.h>
int main(){
	int H;
	int W;
	int N;
	scanf("%d", &H);
	scanf("%d", &W);
	scanf("%d", &N);
	if(H > W){
		if(N%H == 0){
			printf("%d", N/H);
		}else{
			printf("%d", N/H + 1);
		}
	}else{
		if(N%W == 0){
			printf("%d", N/W);
		}else{
			printf("%d", N/W + 1);
	}
	return 0;
}
}