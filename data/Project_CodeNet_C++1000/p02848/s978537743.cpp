#include<stdio.h>
#include<string.h>

	int main(){
	
	int n;
	scanf("%d",&n);
	char arr[10000];
	scanf("%s",arr);
	int len = strlen(arr);
	
	for(int i=0;i<len;i++){
		arr[i] += n;
		if(arr[i] > 'Z'){
			arr[i] -= 26;
		}
		printf("%c",arr[i]);
	}


		return 0;
	}