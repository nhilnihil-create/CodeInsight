#include <stdio.h>

int main() {
	
	int N, check = 0;
	scanf("%d", &N);
	
	if(N % 2 == 1){
		printf("No\n");
		return 0;
	}
	
	char S[N];
	scanf("%s", S);
	
	for(int i = 0; S[i] != '\0'; i++){
		if(S[i] == S[(N / 2) + i]){
			check++;		
		}
	}
	
	if(check == N / 2){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	
	return 0;
}