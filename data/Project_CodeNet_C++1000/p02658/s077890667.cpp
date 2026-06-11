#include <stdio.h>
 
int main(){
	long long int i,T=1,N,A[100001];
	scanf ("%lld",&N);
	for (i=0;i<N;i++){
		scanf ("%lld",&A[i]);
		if (A[i]==0){
			printf("0\n");
			return 0;
		}
	}
	for (i=0;i<N;i++){
		if (A[i] <= 1000000000000000000/T){
			T *= A[i];
		}
		else{
			printf ("-1\n");
			return 0;
		}
	}
	printf ("%lld\n",T);
	return 0;
}