#include <stdio.h>
#include <string.h>
int main (){
	int c;
	char str [100];
	scanf ("%d", &c);
	getchar();
	scanf ("%s", str);
	
	int len = strlen (str);
	if (len <= c) {
		printf ("%s\n", str);
	}else {
		for (int i = 0; i < c; i++){
			printf ("%c", str [i]);
		}
		puts ("...");
	}
	return 0;
}