#include<stdio.h>

int main(){
	char str[10];
	
	scanf("%s", str);
	
	if (str[2]==str[3] && str[4]==str[5]){
		puts("Yes");
	}
	else puts("No");
	return 0;
}