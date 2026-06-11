#include<stdio.h>
#include<string.h>

	
int main(){
	
	int n;
	scanf("%d",&n);
	char arr[n+1];
	
	scanf("%s",arr);
	
	int flag = 1;
	
	for(int i=0;i<(n/2);i++){
	if(arr[i] != arr[i + (n/2)]){
		flag = 0;
	}
}

	if(n%2 != 0){
		flag = 0;
	}

	if(flag == 1){
		printf("Yes");
	}
	else{
		printf("No");
	}
	
		return 0;
	}