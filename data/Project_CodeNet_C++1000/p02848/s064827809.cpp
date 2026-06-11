#include <stdio.h>

int main (){
	int n;
	scanf("%d", &n);
	
	char kata[10001];
	scanf ("%s", kata);
	
	for (int i =0; kata[i] != '\0'; i++){
		if (kata[i] + n > 'Z'){
			printf("%c", kata[i] + n - 26);
		}
		else {
			printf("%c", kata[i] + n);
		}
	}
	
	return 0;
}