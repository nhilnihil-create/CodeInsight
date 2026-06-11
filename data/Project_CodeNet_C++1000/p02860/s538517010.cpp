#include <stdio.h>

int main(){
	int N;
	char S[N];
	scanf("%d", &N);
	scanf("%s", S);
	
	int yes = 0, no = 0;
	
	if(N % 2 == 0){
		for(int i = 0; i < (N / 2); i++){
			if(S[i] == S[i + (N / 2)]){
				yes++;
			}else{
				no++;
			}
		}
		
		if(yes == N / 2){
			printf("Yes");
		}else{
			printf("No");
		}
	}else{
		printf("No");
	}
	
	return 0;
}