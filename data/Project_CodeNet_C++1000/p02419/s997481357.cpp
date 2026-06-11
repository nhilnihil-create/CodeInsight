#include <stdio.h>
#include <string.h>

#define MAX 20
#define MAX2 1000
int main(void)
{
	char tango[MAX]	= {'\0'};
	char word[MAX2]	= {'\0'};
	int cnt			= 0;
	bool flg		= false;
	int i 			= 0;
	char c;

	scanf("%s", tango);

	while((c = getchar()) != EOF) {
		if ((c == ' ') || (c == '\n')) {
			word[i] = '\0';
			i = 0;
			if (strcmp(tango,word) == 0) {
				cnt++;
			}
		}
		else {
			if ((c >= 'A') && (c <= 'Z')) {
				c += ' ';
			}
			word[i] = c;
			i++;
		}
	}

	printf("%d\n",cnt);

	return 0;
}

