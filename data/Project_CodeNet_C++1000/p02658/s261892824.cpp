#include<stdio.h>

int main()
{
	long long tc;
	long long hasil = 1;
	int flag = 1;
	
	scanf("%lld", &tc);
	
	long long input[tc];
	
	for(int i = 0 ; i < tc; i++){
		scanf("%lld", &input[i]);
		if(input[i] == 0){
			printf("0\n");
			return 0;
		}
	}
	
	for(int i = 0; i < tc; i++){
		if(input[i] <= 1000000000000000000/hasil){
			hasil *= input[i];
		}else{
			printf("-1\n");
			return 0;
		}
	}
	printf("%lld\n", hasil);
}