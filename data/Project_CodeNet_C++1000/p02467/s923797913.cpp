#include<cstdio>

int n;

int isPrime(int x){
	int i;
	if(x<2) return 0;
	else if(x==2) return 1;
	if(x%2==0) return 0;
	for(i=3;i*i<=x;i+=2){
		if(x%i==0) return 0;
	}
	return 1;
}

int main(void){
	scanf("%d", &n);
	printf("%d:", n);
	for(int i = 2; i * i <= n; i++){
		//printf("present i's value is %d\n", i);
		while(1){
			if(isPrime(i) == false || n % i != 0) break;
			printf(" %d", i);
			n /= i;
		}
	}
	if(n != 1) printf(" %d", n);
	printf("\n");
	return 0;
}