#include <stdio.h>


int main(){
	int K, A, B;
	scanf("%d %d %d", &K, &A, &B);
	
	for(int i =A; i<=B; i++){
		if(i % K == 0){
			printf("OK");
			return 0;
		}
	}
	printf("NG");
	return 0;
}