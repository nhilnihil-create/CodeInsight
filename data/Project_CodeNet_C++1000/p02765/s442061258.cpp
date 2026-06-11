#include<stdio.h>
int main(){
	int n;
	int r;
	int inr;
	
	scanf("%d %d", &n,&r);
	inr=100*(10-n)+r;
	if (n<10){
		printf("%d", inr);
	}
	else {
		printf("%d", r);
	}
	
	return 0;
}