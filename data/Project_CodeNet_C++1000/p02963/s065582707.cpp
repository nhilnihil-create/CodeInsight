#include<cstdio>
using ull = unsigned long long;

int main(){
    ull S;
    scanf("%llu", &S);
	ull ok = 1e9;//解が存在する値
	ull ng = 0;//解が存在しない値
	while(ok - ng > 1){
		ull mid = ok + ng >> 1;
		if(mid*mid >= S) ok = mid;
		else ng = mid;
	}
    ull a = ok, d = ok;
    if(a*(d-1) >= S) d--;
    printf("0 0 %llu %llu 1 %llu\n", a, a*d - S, d);
	return 0;
}