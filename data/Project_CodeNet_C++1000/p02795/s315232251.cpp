#include <stdio.h>
int main(){
	
	int H, W, N;
	int max, min;
    scanf("%d%d%d", &H, &W, &N);

	if(H>W){
		printf("%d", (N - 1) / H + 1);
	} else {
		printf("%d", (N - 1) / W + 1);
	}
	return 0;	
}