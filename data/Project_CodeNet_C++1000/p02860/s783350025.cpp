#include<stdio.h>
int main(){
	int result1;
	int N;
	scanf("%d", &N);
	char S[N];
	scanf("%s", S);
	int ctr = 0;
	if(N%2 != 0){
		printf("No\n");
	}else{
		result1 = N/2 ;
		for(int i = 0 ; i < result1 ; i++){
			if(S[i] == S[result1 + i])
			ctr++;
		}
		if(result1 == ctr){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}