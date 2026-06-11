#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	getchar();
	
	char letter[n+1];
	scanf("%[^\n]", letter);
	
	if(n % 2 == 0){
		int mid = n / 2;
		
		int flag = 0;
		for(int i = 0; i < mid; i++){
			if(letter[i] != letter[i + mid]){
				flag = 1;
				break;
			}
		}
		
		if(flag == 0){
			printf("Yes");
		}
		else{
			printf("No");
		}
	}
	else{
		printf("No");
	}
	
	return 0;
}