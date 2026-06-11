#include <stdio.h>

int main(){
	
	int N;
	scanf("%d", &N);
	char S[N+1];
	
	scanf("%s", S);
	
	
if(N%2==1){
	puts("No");
}
else{
	int counter=0;

	int x = N/2;
	for(int i=0;i<x;i++){
		if (S[i] == S[x+i]){
		counter++;	
		}
	}
	
	if(counter == x){
		puts("Yes");
	}
	
	else{
		puts("No");
	}
}
	return 0;
}