#include<cstdio>

int main(){
	long long n,a = 1;
	scanf("%ld", &n);
	while(n){
		a *= n;
		n--;
	}
	printf("%ld\n", a);
	return 0;
}