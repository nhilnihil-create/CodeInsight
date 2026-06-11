#include <stdio.h>

int main(){
	long long int n;
	scanf("%lld",&n);
	long long int num[n]={};
	long long int res=1;
	long long int temp;
	for (int i=0;i<n;i++){
		scanf("%lld",&num[i]);
	}
	for(int i=0;i<n;i++){
	
		if (num[i]==0){
			printf("0\n");
			return 0;
		}
		}
	for (int i=0;i<n;i++){
		if(num[i]<=1000000000000000000/res){
			res*=num[i];
		}
		else{
			printf("-1\n");
			return 0;
		}
	}	
		printf("%lld",res);
		return 0;
	}
	