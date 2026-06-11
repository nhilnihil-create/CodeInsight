#include <stdio.h>

int main(){
	
	int n,i;
	char s[100];
	scanf("%d %s", &n,&s);
	
	if(n % 2 != 0){
		printf("No");
		return 0;
	}
	for(i = 0; i < n/2; i++){
		if(s[i] != s[n/2 + i]){
			printf("No");
			return 0;
		}
	}
	printf("Yes");
	return 0;
}