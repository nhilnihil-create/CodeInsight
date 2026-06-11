#include<stdio.h>

int main(){
	
	long long int tc;
	long long int temp=1;
	
	scanf("%lld",&tc);
	long long int input[100005];
	bool printtemp = false;
	bool nextloop = true;
	for(long long int i=0;i<tc;i++){	
		scanf("%lld",&input[i]);
		if(input[i] == 0){
			printf("0\n");
			nextloop = false;
			break;
		}	
	}
	if ( nextloop ){
		for(long long int i =0;i<tc;i++){
			if(1000000000000000000/temp < input[i]){
				printf("-1\n");
				break;
			}
			temp *=input[i];
			//printf("Temp [%d] : %lld\n",i,temp);
			if(i >= tc-1){
				printtemp = true;
			} 
		}	
	}
	

	if(printtemp) printf("%lld\n",temp);
	
	
	return 0;
}