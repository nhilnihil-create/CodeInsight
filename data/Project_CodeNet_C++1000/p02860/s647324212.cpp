#include<stdio.h>
#include<string.h>
int main(){
	int n;
	scanf("%d" , &n);
	char str[n];
	scanf("%s" , &str);
	if(n%2 == 1){
		printf("No\n");
		return 0;
	}
	for(int i = 0 ; i < n / 2 ; i++){
		if(str[i] == str[i + n / 2]){
			continue;
		}
		else{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}