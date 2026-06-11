#include <stdio.h>

int main(){

int N;
scanf("%d", &N);
long long int sum = 0;

for(int i = 1; i <= N; i++){
	if (i %3 != 0 && i%5 != 0){
		sum += i;
}
}

	printf("%lld\n", sum);


return 0;
}