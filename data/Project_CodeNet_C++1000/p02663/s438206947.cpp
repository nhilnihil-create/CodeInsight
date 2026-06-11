#include <stdio.h>

int main(){
	int H1, M1, H2, M2, K;
	scanf("%d %d %d %d %d",&H1, &M1, &H2, &M2, &K);
	
	int hours = H2 - H1;
	int minutes = M2 - M1;
	
	int sum = (hours * 60) + minutes;
	int total = sum - K;
	
	printf("%d\n", total);
	
	
	return 0;
}
