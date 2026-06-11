#include<stdio.h>

int main(){
	long long int tc;
	scanf("%lld", &tc);
	long long int n[tc], tot=1;
	for(long long int i=0; i<tc; i++){
//		tot<1000000000000000000
		scanf("%lld", &n[i]);
		if(n[i]==0){
			tot=0;
			printf("%lld\n", tot);
			break;
		}
	}
	if(tot>0){
	for(long long int i=tc-1; i>=0; i--){
		if(tot>1000000000 && n[i]>1000000000){
			tot=0;
			  printf("-1\n");
			break;
		}
		else if(tot*n[i]>1000000000000000000){
			tot=0;
			printf("-1\n");
		}
		else{
			tot*=n[i];	
		}
	}
	}
	if(tot>0){
		printf("%lld\n", tot);
	}
	return 0;
}