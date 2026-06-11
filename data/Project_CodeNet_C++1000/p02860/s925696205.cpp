#include <stdio.h>
int main(){
	int N;
	scanf ("%d", &N);

	char S[N + 1];
	scanf ("%s", &S);
	
	if (N % 2 == 1){
		puts ("No");
	}
	else {
		int flag = 1;
		for (int i = 0; i < N/2; i++){
			if (S[i] != S[i + N/2]){
			flag = 0;	
			}
			}
	if (flag){
		puts ("Yes");
	}
	else {
		puts ("No");
	}
}
	return 0;
}