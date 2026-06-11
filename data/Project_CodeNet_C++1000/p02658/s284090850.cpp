#include<stdio.h>
//#define MAX_SIZE 100000
int main(){
	long long int N;
	scanf("%lld",&N);
	long long int A[N];
	long long int i;
	long long int prod=1;
	long long int x=1e18;

	for(i=0;i<N;i++){
		scanf("%lld",&A[i]);
	}
	for(i=0;i<N;i++){
		if(A[i]==0){
			puts("0");
			return 0;
		}
	}
	for(i=0;i<N;i++){
		if(A[i]<=x/prod){
			prod*=A[i];
			}
			else{
				puts("-1");
				return 0;
				}
	}
	
	printf("%lld\n",prod);
	
	return 0;
}
