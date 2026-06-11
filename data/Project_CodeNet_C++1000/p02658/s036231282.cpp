#include <stdio.h>
int main(){
	int N;
	unsigned long long int sum=1;
	
	scanf("%d", &N);
	
	unsigned long long int A[N];

	
	for(int i=0;i<N;i++){
		scanf("%llu", &A[i]); 
		if(A[i]==0){
			printf("0");
			return 0;
	}
	for(int i=0;i<N; i++){
		
		}
	}
		for(int i=0; i<N;i++){
			if(A[i]<=1000000000000000000/sum){
				sum*=A[i];
			
		}
		else{
			printf("-1");
		return 0;
		}
	}
	printf("%lld", sum);
	
	return 0;
}

