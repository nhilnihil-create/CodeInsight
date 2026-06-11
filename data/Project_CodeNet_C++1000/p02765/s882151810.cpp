#include <stdio.h>

int main(){
	int N, R, IR, results;
	scanf("%d %d", &N, &R);
	if(N >= 10){results = R; printf("%d", results);}
	else if (N < 10){IR = 10 - N; results = 100 * IR + R; printf("%d", results);}
	return 0;
}