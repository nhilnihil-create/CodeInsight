#include<stdio.h>
int main(){
	long long int t;
	scanf("%lld",&t);
	long long int number[t]={0};
	long long int hasil=1;
	
	for(long long int i=0;i<t;i++){
		scanf("%lld",&number[i]);
	}
	for(long long int i=0;i<t;i++){
		if(number[i]==0){
			printf("0\n");
			return 0;
		}
	}
	for(int i=0;i<t;i++){
		if(number[i]<=1000000000000000000/hasil){
			hasil=hasil*number[i];
		}
		else{
			printf("-1\n");
			return 0;
		}
	}
	printf("%lld",hasil);
	return 0;
}