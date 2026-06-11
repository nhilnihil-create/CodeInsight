#include <stdio.h>

int main(){
	
	int H1, M1;
	int H2, M2;
	int K;
	
	scanf("%d %d %d %d %d", &H1, &M1, &H2, &M2, &K);
	
	int time1 = H1 * 60 + M1;
	int time2 = H2 * 60 + M2;
	int total = (time2 - K) - time1;
	
	printf("%d\n", total);
	
	return 0;
}