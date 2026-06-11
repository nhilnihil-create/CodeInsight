#include <stdio.h>
#include <string.h>

void change(int n, char letter[], int len){
	for(int i = 0; i < len; i++){
		for(int j = 1; j <= n; j++){
			if(letter[i] == 'Z'){
				letter[i] = 'A';
				continue;
			}
			letter[i] ++;
		}
		printf("%c", letter[i]);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	getchar();
	
	char letter[10002];
	scanf("%[^\n]", letter);
	
	int len = strlen(letter);
	
	change(n, letter, len);
	
	return 0;
}