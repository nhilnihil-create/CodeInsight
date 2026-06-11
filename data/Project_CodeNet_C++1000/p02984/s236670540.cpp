#include<cstdio>
using ull = unsigned long long;

int main(){
	int N;
	scanf("%d", &N);
	ull A[N], sum = 0;
	for (int i = 0; i < N; ++i){
		scanf("%llu", A + i);
		sum += A[i];
	}
	sum >>= 1;
	for (int i = 0; i < N >> 1; ++i){
		sum -= A[(i << 1) + 1];
	}
	printf("%llu", sum << 1);
	for (int i = 1; i < N; ++i){
		printf(" %llu", (sum = A[i - 1] - sum) << 1);
	}
	printf("\n");
	return 0;
}