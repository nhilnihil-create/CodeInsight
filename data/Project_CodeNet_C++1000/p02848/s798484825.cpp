#include <stdio.h>
#include <string.h>
int main(){
	int swap;
	scanf("%d", &swap);
	char kata[10000];
	scanf("%s", kata);
	for(int i = 0; i < strlen(kata); i++){
		kata[i] += swap;
		if(kata[i] > 'Z'){
			kata[i] -= 26;
		}
	}
	for(int i = 0; i < strlen(kata); i++){
		printf("%c", kata[i]);
	}
	
	return 0;
}