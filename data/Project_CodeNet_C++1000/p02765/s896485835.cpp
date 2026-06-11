#include <stdio.h>
int main(){
	int N, R;
	scanf("%d %d", &N, &R);
	if (N < 10){
		printf("%d",(10 - N) * 100 + R);
	} else {
			printf("%d", R); 
	}

	return 0;

}