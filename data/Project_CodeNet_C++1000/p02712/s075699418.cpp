#include<stdio.h>

#define ll long long

int main(){
	int n;
	scanf("%d", &n);
	ll sum = 0;
	for(int i = 1; i <= n; i++){
		if(i % 3 == 0 && i % 5 == 0){
			continue;
		}
		if(i % 3 == 0 || i % 5 == 0){
			continue;
		}
		else{
			sum += i;
		}
	}
	printf("%lld\n", sum);
	return 0;
}
