#include<stdio.h>

int strlen(char str[]){
	int len = 0;
	for(int i = 0; str[i] != '\0'; i++){
		len++;
	}
	return len;
}

int main(){
	int n;
	scanf("%d", &n);
	getchar();
	char str[n];
	char leftArr[n / 2];
	char rightArr[n / 2];
	int counter = 0;
	scanf("%s", str);
	int len = strlen(str);
	if(len % 2 != 0){
		printf("No\n");
	}
	else if(len % 2 == 0){
		int mid = len / 2;
		for(int i = 0; i < mid; i++){
			leftArr[i] = str[i];
		}
		for(int i = 0; i < mid; i++){
			rightArr[i] = str[mid + i];
		}
		for(int i = 0 ; i * 2 < len; i++){
			if(rightArr[i] == leftArr[i]){
				counter++;
			}
		}
		if(counter == len / 2){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
        return 0;
}