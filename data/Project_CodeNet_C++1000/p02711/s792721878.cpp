#include <stdio.h>

int main(){
	int n;
	scanf("%d" ,&n);
	if(n >= 100 && n <= 999){
		if(n % 10 == 7){
			printf("Yes\n");
		}
		else if(n / 10 % 10 == 7){
			printf("Yes\n");
		}
		else if(n / 100 == 7){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	return 0;
}