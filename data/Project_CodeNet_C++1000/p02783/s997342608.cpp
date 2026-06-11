#include <stdio.h>

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	int total = (n+k-1)/k;
	printf("%d", total);
	
	return 0;
}