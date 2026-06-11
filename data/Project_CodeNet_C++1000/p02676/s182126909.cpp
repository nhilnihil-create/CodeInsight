#include <stdio.h>
#include <string.h>
int main (){
	int j;
	char character[200];
	scanf("%d", &j);
	getchar();
	
	
	scanf("%[^\n]", &character);
	int s = strlen(character);
	
	for(int i=0;i<j && character[i] != '\0';i++){
		printf("%c", character[i]);
	}
	if(s>j){
		printf("...");
	}
		
	return 0; 
}