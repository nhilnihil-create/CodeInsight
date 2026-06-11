#include <stdio.h>
#include <string.h>

int main (){
	char huruf[10000];
	int input;
	scanf("%d",&input);
	getchar();
	scanf ("%[^\n]",&huruf);
	int len = strlen (huruf);
	input = input % 26;
	for (int i = 0 ; i < len; i++){
		if (huruf[i]-'A' + input >= 26){
			huruf[i] = ((huruf[i]-'A' + input) % 26 )+'A';
		} else {
			huruf [i] +=input; 
		}
		printf("%c", huruf[i]);
	}
	
}
