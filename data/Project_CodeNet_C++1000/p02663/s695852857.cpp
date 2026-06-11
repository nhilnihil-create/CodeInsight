#include <stdio.h>

int main(){
	int H1, H2, M1, M2, K;
	H1, H2 >= 0 && H1, H2 <= 23;
	M1, M2 >= 0 && M1, M2 <= 60;
	int HM1, HM2;
	scanf("%d %d %d %d %d", &H1, &M1, &H2, &M2, &K);
	HM1 = H1 * 60 + M1;
	HM2 = H2 * 60 + M2;
	printf("%d", HM2 - HM1 - K);
	
	
	
	
	
	return 0;
}