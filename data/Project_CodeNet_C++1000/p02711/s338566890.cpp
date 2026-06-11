#include <stdio.h>

int main(){
	int N;
	scanf("%d", &N);

	if (N / 100 == 7){
		puts("Yes");
	}else if ((N % 100)/10 == 7){
		puts("Yes");
	}else if (N % 10 == 7){
		puts("Yes");
	}else{
		puts("No");
	}
return 0;
}