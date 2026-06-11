#include<stdio.h>
int main (){

	long long int berapaKali;	
	scanf("%lld", &berapaKali);
	long long int a1[berapaKali];
	long long int a2 = 1;
	long long int max = 1000000000000000000;
	long long int hasil ;
	
	for(int j=0;j<berapaKali;j++){
		scanf("%lld", &a1[j]);
	}
	
	for(int h=0;h<berapaKali;h++){
	
		if(a1[h]==0){
			printf("0\n");
			return 0;
		}
	}
	for(int i=0;i<berapaKali;i++){
		if(a1[i]<=max/a2){	
		a2*= a1[i];	
		}else{
		printf("-1\n");
		return 0;
		}
	}
	
	printf("%lld\n", a2);

	return 0;
}