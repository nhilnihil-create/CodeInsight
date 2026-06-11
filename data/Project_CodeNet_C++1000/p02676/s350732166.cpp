#include<stdio.h>
#include<string.h>

int main(){

	int n;
	char arr[101];
	scanf("%d",&n);
	scanf("%s",&arr);
	
	int len = strlen(arr);
	
	if(len > n){
		for(int i=0;i<n;i++){
			printf("%c",arr[i]);
		}
		printf("...");
	}
	else if(len == n || len < n){
		printf("%s",arr);
	}

	

    return 0;
}
