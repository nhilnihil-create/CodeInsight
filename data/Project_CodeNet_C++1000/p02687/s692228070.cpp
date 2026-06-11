#include<stdio.h>
int main(void)
{
    char s[4];
	scanf("%s",s);
	if(s[1]=='B') {
		s[1] = 'R';
		printf("%s\n",s);
	}
	else {
		s[1]= 'B';
		printf("%s\n",s);
	}
	return 0;
	}