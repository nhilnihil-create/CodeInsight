#include <stdio.h>
#include <string.h>

int main (){
	int k;
	scanf ("%d", &k);
	char str[101];
	scanf ("%s", &str);
	
	int len = strlen (str);
	if (len <= k){
		printf ("%s", str);
	}	
	else {
		for (int i = 0; i < k; i++){
			printf ("%c", str[i]);
		}
		puts ("...");
	}
	
	return 0;
}