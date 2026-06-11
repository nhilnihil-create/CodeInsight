#include <stdio.h>
#include <string.h>

// ?°????????????§????????????
void toUpper(char *str) {
	int len = strlen(str);
	if (len <= 0) {
		return;
	}
	for (int i = 0; i < len; i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] &= 0xdf;	//?°????????????§??????
		}
	}
}

int main(void) {


	char word[16];
	char sentense[1024];
	char t[1024];
	char tmp[16];

	int num[50];
	int combo[50];

	scanf("%s", word);
	toUpper(word);
	int cnt = 0;
	while (fgets(sentense, 1024, stdin) != NULL) {
		if ( strcmp(sentense, "END_OF_TEXT\n") == 0 ) {
			break;
		}
		toUpper(sentense);
		int len = strlen(sentense);
		if (len > 0) {
			sentense[len - 1] = '\0';
		}
		char *ptr = strtok(sentense, " ");
		while (ptr != NULL ) {
			if (strcmp(ptr, word) == 0) {
				cnt++;
			}
			ptr = strtok(NULL, " ");
		}

	}

	printf("%d\n", cnt);

	return 0;

}