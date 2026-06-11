#include <stdio.h>

int main(){
	int n;
	scanf("%d" ,&n);
	char str[n + 1];
	scanf("%s" ,str);
	if(n % 2 == 1){
		puts("No");
	}
	else if(n % 2 == 0){
		int flag = 1;
		for(int i = 0; i < n / 2; i++){
			if(str[i] != str[i + n / 2]){
			flag = 0;
			}
		}
		if(flag == 0){
			puts("No");
		}
		else if(flag == 1){
			puts("Yes");
		}
	}
	return 0;
}