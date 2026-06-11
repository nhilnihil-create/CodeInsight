#include <stdio.h>

int main (){
	
	char s[15];
	scanf ("%s", s);
	if (s[2] == s[3] && s[4] == s[5]){
		printf ("Yes\n");
	}
	else {
		printf ("No\n");
	}	
	return 0;
}