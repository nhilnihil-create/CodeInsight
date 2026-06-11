#include <stdio.h>
int main () {
	long long int N;
	long long int sum=0;
	scanf("%lld",&N);
	for(int i=1;i<=N;i++) {
		if(i%15==0) {
		continue;
		} else if(i%5==0) {
		continue;
		} else if(i%3==0) {
		continue;
		}
	sum+=i;
}
	printf("%lld\n", sum);
	return 0;
}