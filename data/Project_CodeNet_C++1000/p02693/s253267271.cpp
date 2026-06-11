#include <stdio.h>
int main() {

    int K, A, B;
    int sum=0;
    
    scanf("%d", &K);
    scanf("%d %d", &A, &B);
	
	for(int i=A;i<=B;i++) {
		if(i % K == 0) {
			sum++;
		}
	}
		if(sum !=0) {
			printf("OK");
		}else{
			printf("NG");
		}
    return 0;
}