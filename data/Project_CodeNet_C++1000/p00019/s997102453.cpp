#include <cstdio>

using namespace std;

int main(void){
	long long int n, mul = 1;
	scanf("%lld",&n);
	while(n){
		mul *= n;
		n--;
	}
	printf("%lld\n",mul);
	return 0;
}