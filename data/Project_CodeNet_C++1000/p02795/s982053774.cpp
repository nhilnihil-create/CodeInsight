#include <stdio.h>

int main (){
	
	int H, W, N;
	scanf("%d %d %d", &H, &W, &N);
	
	int xx;
	
	if(H >= W) {
        if(N % H == 0) {
            xx = N / H;
        } else {
            xx = N / H + 1;
        }
    } else {
        if(N % W == 0) {
            xx = N / W;
        } else {
            xx = N / W + 1;
        }
    }
	printf("%d", xx);
	
	return 0;
}