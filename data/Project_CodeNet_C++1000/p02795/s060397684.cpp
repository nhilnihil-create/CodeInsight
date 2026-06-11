#include <stdio.h>

int main() {
	
	int H, W, N;
	scanf("%d", &H);
	scanf("%d",&W);
	scanf("%d", &N);
	int temp, count = 0;
	
	H > W ? temp = H : temp = W;
	
	for(int i = 0; i < N; i += temp){
		count++;
	}
	printf("%d\n", count);
	
	return 0;
}