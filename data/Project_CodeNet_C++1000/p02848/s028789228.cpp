#include<stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	char str[10002];
	scanf("%s", str);
	for(int i = 0; str[i] != '\0'; i++){
		int temp = n;
		if(str[i] + n > 'Z'){
			temp = temp - ('Z' - str[i]);
			str[i] = 'A' + (temp - 1);
		}
		else{
			str[i] = str[i] + n;
		}
	}
	printf("%s", str);
	
	
	return 0;
}