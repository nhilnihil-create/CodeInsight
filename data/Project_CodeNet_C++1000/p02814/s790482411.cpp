#include<cstdio>
using ull = unsigned long long;

ull GreatestCommonDivisor(ull a, ull b){
	ull r = b;
	while(a % b != 0){
		r = a % b;
		a = b;
		b = r;
	}
	return r;
}

int main(){
    unsigned N, M;
    scanf("%u %u", &N, &M);
    unsigned a[N];
    for(int i = 0; i < N; ++i){
        scanf("%u", a + i);
        a[i] >>= 1;
    }
    unsigned i = 0, lcm = 1;
    while(i < N && a[i]/GreatestCommonDivisor(a[i], lcm) <= M/lcm){
        lcm *= a[i]/GreatestCommonDivisor(a[i], lcm);
        i++;
    }
    if(i < N){
        printf("0\n");
        return 0;
    }
    i = 0;
    while(i < N && lcm/a[i] & 1u) i++;
    printf("%u\n", i < N ? 0 : M/lcm + 1 >> 1);
	return 0;
}