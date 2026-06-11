#include <stdio.h>
int main(){
	
	int N, pages;
	scanf("%d", &N);
	int papers = (N % 2 == 0) ? (N / 2) : ((N / 2) + 1);
	printf("%d\n", papers);
	return 0;
}