#include<cstdio>
using ull = unsigned long long;

int main(){
    ull N;
    scanf("%llu", &N);
    printf("%llu\n", N*(N - 1)>>1);
	return 0;
}