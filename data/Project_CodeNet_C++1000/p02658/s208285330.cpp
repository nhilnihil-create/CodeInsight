#include <stdio.h>

int main() {

long long int n;
long long int t;
scanf("%lld", &t);

long long int num[t];
long long int sum = 1;

for(long long int i = 0; i<t; i++){
	scanf("%lld", &n);
	num[i] = n;
}

for(long long int i = 0; i<t; i++){
	if(num[i]==0){
		printf("0\n");
		return 0;
	}
}

for(long long int i = 0; i<t; i++){
	if(num[i]<=1000000000000000000/sum){
	sum *= num[i];
	}
	else{ 
	printf("-1\n");
	return 0;
	}	
}

printf("%lld\n", sum);

    return 0;
}
