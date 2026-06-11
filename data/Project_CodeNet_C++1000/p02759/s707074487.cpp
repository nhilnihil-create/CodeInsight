#include <stdio.h>

int main(){
	int N,i;
	scanf("%d",&N);
	for(i=1;i<N;i++){
		N--;
	}
	printf("%d",N);
	return 0;
}