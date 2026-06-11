#include <stdio.h>
#include <string.h>

int main(){
	int H, W, N, X, Sum=0, Count=0;
	scanf ("%d %d %d", &H, &W, &N);
	
	if (H>=W){
		X=H;
	}
	else{
		X=W;
	}
	
	while (Sum<N){
		Sum+=X;
		Count++;
	}
	
	printf ("%d\n", Count);
	return 0;
}
