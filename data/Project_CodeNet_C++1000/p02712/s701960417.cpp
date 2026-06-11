#include<stdio.h>

int main()
{
	int n;
	long long sum = 0;
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++){
		int flag = 1;
		if(i % 3 == 0 && i % 5 == 0){
			flag = 0;
		}else if(i % 3 == 0){
			flag = 0;
		}else if(i % 5 == 0){
			flag = 0;
		}if(flag == 1){
			sum += i;
		}
	}
	printf("%lld\n", sum);
}