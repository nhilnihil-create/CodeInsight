#include <stdio.h>

int main () {
	
	char s[10];
	scanf("%s", &s);
	
	if(s[1] == 'B'){
		s[1] = 'R';
		printf("%s", s);
	}else if (s[1] == 'R'){
	 	s[1] = 'B';
		printf("%s", s);
	}
	
	return 0;
}