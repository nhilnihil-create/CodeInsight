#include<stdio.h>

int main(){
	int H1, M1, H2, M2, K;
	scanf("%d %d %d %d %d", &H1, &M1, &H2, &M2, &K);
	int x;
	
	x = ((H2 - H1) * 60) + (M2 - M1) - K;
	
	printf("%d", x);
	
return 0;
}