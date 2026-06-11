#include <stdio.h>


int main() {
	int H, W, N, hasil;
	
	scanf("%d %d %d", &H, &W, &N);
	
	if(H > W) {
		hasil = (N+H-1)/H;
	} else {
		hasil = (N+W-1)/W;
	}
	
	printf("%d\n", hasil);
	
	return 0;
}