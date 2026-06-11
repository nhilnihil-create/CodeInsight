#include <stdio.h>

int main(){
 	long long N;
 	scanf("%lld", &N);
 	long long A[N], sum = 1;
 	
 	for(long long i=0; i<N; i++){
 		scanf("%lld", &A[i]);
	}
	
	for(long long i=0; i<N; i++){
 		if(A[i] == 0){
 			printf("0\n");
 			return 0;
		 }
	}
	
	for(long long i=0; i<N; i++){
		if(A[i] <= (1000000000000000000/sum)){
			sum *= A[i];
 		} else{
 			printf("-1\n");
            return 0;
		 }
 	}

		printf("%lld\n", sum);
 	
	return 0;
}