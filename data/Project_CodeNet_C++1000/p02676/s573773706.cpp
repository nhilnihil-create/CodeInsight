#include <stdio.h>
#include <string.h>
int main(){
	int n;
	scanf("%d",&n);
	char arr[105];
	scanf("%s", arr);
	int len = strlen(arr);
	
	if (len > n){
		for (int i = 0; i < n;i++){
			printf("%c",arr[i]);
			}
			printf("...");
	}
	else{
		printf("%s",arr);
	}
}