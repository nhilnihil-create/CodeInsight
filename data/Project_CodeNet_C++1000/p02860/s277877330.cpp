#include <stdio.h>
int main(){
	int N;
	scanf("%d", &N);
	char S[N];
	scanf("%s", S);
	if(N%2){
		printf("No");
		return 0;
	} else {
		for(int i=0;i<N/2;i++){
			if(S[i]==S[i + N/2]){
				
			}	else {
				printf("No");
				return 0;
			}
		}	
	}
	printf("Yes");
	return 0;
}