#include <stdio.h>

int main(){
	int N;
	scanf("%d", &N);
	
	int a = N / 100, b = (N - a * 100) / 10, c = N % 10;
	
	if(a== 7 || b == 7 || c == 7){
		puts("Yes");
	}
	else{
		puts("No");
	}
	
	return 0;
}