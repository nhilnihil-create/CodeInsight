#include<stdio.h>

int main(){
	
	int H, A;
	scanf("%d %d", &H, &A);
	int attacks = (H % A == 0) ? (H / A) : ((H / A) + 1 );
	printf("%d\n", attacks);
	
	return 0;
}